using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;

namespace RipMons
{
	class Program
	{
		enum Types
		{
			Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel,
			None,
			Fire, Water, Grass, Electric, Psychic, Ice, Dragon, Dark
		}
		enum EggGroups
		{
			Null,
			Monster, Water1, Bug, Flying, Ground, Fairy, Plant,
			Human, Water3, Mineral, Indeterminate, Water2,
			Ditto, Dragon, None
		}

		enum LevelGradients
		{
			Medium, Flux, Erratic, MidSlow, Quick, Slow, Unk1, Unk2
		}

		enum EvolutionTypes
		{
			Null, Happy, HappyDay, HappyNight, Level, Trade, ItemTrade, Item, AttGtDef,
			AttEqDef, AttLtDef, HighPers, LowPers, AllowCreate, CreateExtra, Beauty
		}

		static void Main(string[] args)
		{

			BinaryReader rom = new BinaryReader(File.Open("d:/Pokéhacks/fr.gba", FileMode.Open), Encoding.Default);
			XmlDocument xml = new XmlDocument();
			List<XmlElement> monNodes = new List<XmlElement>();
			List<XmlElement> dexNodes = new List<XmlElement>();
			List<XmlElement> bstNodes = new List<XmlElement>();
			List<XmlElement> movNodes = new List<XmlElement>();
			List<XmlElement> tmsNodes = new List<XmlElement>();
			List<XmlElement> evoNodes = new List<XmlElement>();

			Console.WriteLine("Reading move names...");
			string[] moves = ReadDefs("../../../../../data/moves.h");
			Console.WriteLine("Reading ability names...");
			string[] abilities = ReadDefs("../../../../../data/abilities.h");
			Console.WriteLine("Reading item names...");
			string[] items = ReadDefs("../../../../../data/itemdata.h");
			items[0] = "0";

			Console.WriteLine("Reading national dex order...");
			UInt16[] NationalDexOrder = new UInt16[412];
			rom.BaseStream.Seek(0x251FEC, SeekOrigin.Begin);
			for (int i = 0; i < 411; i++)
				NationalDexOrder[i] = rom.ReadUInt16();
			NationalDexOrder[0] = 0;

			Console.WriteLine("Reading TM table...");
			UInt16[] TMs = new UInt16[64];
			rom.BaseStream.Seek(0x45A5A4, SeekOrigin.Begin);
			for (int i = 0; i < 64; i++)
				TMs[i] = rom.ReadUInt16();

			Console.WriteLine("Reading names and creating nodes...");
			for (int i = 0; i < 411; i++)
			{
				XmlElement thisMon = xml.CreateElement("mon");
				monNodes.Add(thisMon);
				rom.BaseStream.Seek(0x245EE0 + (i * 11), SeekOrigin.Begin);
				string name = Translation.CleanUp(Translation.ToAscii(Translation.ReadString(rom)));
				thisMon.SetAttribute("name", name);
			}

			#region Dex
			Console.WriteLine("Reading dex information...");
			for (int i = 0; i < 387; i++ )
			{
				XmlElement dex = xml.CreateElement("dex");
				rom.BaseStream.Seek(0x44E850 + (i * 36), SeekOrigin.Begin);
				string type = Translation.CleanUp(Translation.ToAscii(Translation.ReadString(rom)));
				dex.SetAttribute("type", type);
				rom.BaseStream.Seek(0x44E850 + (i * 36) + 12, SeekOrigin.Begin);
				dex.SetAttribute("height", rom.ReadInt16().ToString());
				dex.SetAttribute("weight", rom.ReadInt16().ToString());
				long dexText1 = rom.ReadUInt32() - 0x8000000;
				long dexText2 = rom.ReadUInt32() - 0x8000000;
				dex.SetAttribute("moffset", rom.ReadInt16().ToString());
				dex.SetAttribute("mscale", rom.ReadInt16().ToString());
				dex.SetAttribute("toffset", rom.ReadInt16().ToString());
				dex.SetAttribute("tscale", rom.ReadInt16().ToString());

				rom.BaseStream.Seek(dexText1, SeekOrigin.Begin);
				string dexText = Translation.ToAscii(Translation.ReadString(rom));
				rom.BaseStream.Seek(dexText2, SeekOrigin.Begin);
				dexText += '\n' + Translation.ToAscii(Translation.ReadString(rom));
				dex.AppendChild(xml.CreateTextNode(dexText));
				dexNodes.Add(dex);
			}
			#endregion

			#region Base stats
			Console.WriteLine("Reading base stats...");
			rom.BaseStream.Seek(0x254784, SeekOrigin.Begin);
			for (int i = 0; i < 411; i++)
			{
				XmlElement bst = xml.CreateElement("stats");
				bst.SetAttribute("hp", rom.ReadByte().ToString());
				bst.SetAttribute("atk", rom.ReadByte().ToString());
				bst.SetAttribute("def", rom.ReadByte().ToString());
				bst.SetAttribute("spd", rom.ReadByte().ToString());
				bst.SetAttribute("sat", rom.ReadByte().ToString());
				bst.SetAttribute("sdf", rom.ReadByte().ToString());
				bst.SetAttribute("type1", ((Types)rom.ReadByte()).ToString());
				bst.SetAttribute("type2", ((Types)rom.ReadByte()).ToString());
				bst.SetAttribute("rate", rom.ReadByte().ToString());
				bst.SetAttribute("expyield", rom.ReadByte().ToString());
				bst.SetAttribute("effort", "0x" + rom.ReadUInt16().ToString("X"));
				bst.SetAttribute("item1", items[rom.ReadUInt16()]);
				bst.SetAttribute("item2", items[rom.ReadUInt16()]);
				bst.SetAttribute("gender", rom.ReadByte().ToString());
				bst.SetAttribute("hatch", rom.ReadByte().ToString());
				bst.SetAttribute("happy", rom.ReadByte().ToString());
				bst.SetAttribute("lvgrad", ((LevelGradients)rom.ReadByte()).ToString());
				bst.SetAttribute("egg1", ((EggGroups)rom.ReadByte()).ToString());
				bst.SetAttribute("egg2", ((EggGroups)rom.ReadByte()).ToString());
				bst.SetAttribute("ability1", abilities[rom.ReadByte()]);
				bst.SetAttribute("ability2", abilities[rom.ReadByte()]);
				bst.SetAttribute("safari", rom.ReadByte().ToString());
				bst.SetAttribute("color", rom.ReadByte().ToString("X"));
				rom.ReadInt16();
				bstNodes.Add(bst);
			}
			#endregion

			#region Movesets
			Console.WriteLine("Reading movesets...");
			rom.BaseStream.Seek(0x257496, SeekOrigin.Begin);
			movNodes.Add(xml.CreateElement("moveset"));
			for (int i = 1; i < 412; i++)
			{
				XmlElement moveset = xml.CreateElement("moveset");
				do
				{
					int j = rom.ReadUInt16();
					if (j == 0xFFFF)
						break;
					XmlElement move = xml.CreateElement("move");
					move.SetAttribute("level", ((j & 0xFE00) / 512).ToString());
					move.SetAttribute("id", moves[j & 0x1FF]);
					//move.SetAttribute("number", (j & 0x1FF).ToString());
					moveset.AppendChild(move);
				} while (true);
				movNodes.Add(moveset);
			}
			#endregion

			#region TMs
			Console.WriteLine("Reading TM sets...");
			rom.BaseStream.Seek(0x252BC8, SeekOrigin.Begin);
			for (int i = 0; i < 411; i++)
			{
				XmlElement TMSet = xml.CreateElement("tmset");
				//byte[] TMBytes = rom.ReadBytes(8);
				System.Collections.BitArray TMBits = new System.Collections.BitArray(rom.ReadBytes(8));
				for (int t = 0; t < 58; t++)
				{
					//int j = (TMBytes[t / 8] & (2 ^ (t % 8)));
					//if (j > 0)
					if(TMBits[t])
					{
						XmlElement tm = xml.CreateElement("tm");
						tm.SetAttribute("number", (t + 1).ToString());
						if(t > 49)
							tm.SetAttribute("id", moves[TMs[t]] + " (HM)");
						else
							tm.SetAttribute("id", moves[TMs[t]]);
						tm.SetAttribute("number", (t + 1).ToString());
						TMSet.AppendChild(tm);
					}
				}
				tmsNodes.Add(TMSet);
			}
			#endregion

			#region Evolutions
			Console.WriteLine("Reading evolutions...");
			rom.BaseStream.Seek(0x25977C, SeekOrigin.Begin);
			evoNodes.Add(xml.CreateElement("evolutions"));
			for (int i = 0; i < 411; i++)
			{
				XmlElement evoSet = xml.CreateElement("evolutions");
				for (int e = 0; e < 5; e++)
				{
					XmlElement evo = xml.CreateElement("evo");
					EvolutionTypes type = (EvolutionTypes)rom.ReadUInt16();
					UInt16 param = rom.ReadUInt16();
					UInt16 target = rom.ReadUInt16();
					rom.ReadUInt16();
					evo.SetAttribute("type", type.ToString());
					if ((EvolutionTypes)type == EvolutionTypes.Item || (EvolutionTypes)type == EvolutionTypes.ItemTrade)
						evo.SetAttribute("param", items[param]);
					else
						evo.SetAttribute("param", param.ToString());
					evo.SetAttribute("target", monNodes[target].GetAttribute("name"));
					if(type > 0)
						evoSet.AppendChild(evo);
				}
				evoNodes.Add(evoSet);
			}
			#endregion

			Console.WriteLine("Connecting the dots...");
			for (int i = 0; i < 411; i++)
			{
				int j = NationalDexOrder[i];
				if (i >= 252 && i < 277)
					j = 0;
				monNodes[i].AppendChild(dexNodes[j]);
				monNodes[i].AppendChild(bstNodes[i]);
				if (movNodes[i].ChildNodes.Count > 0)
					monNodes[i].AppendChild(movNodes[i]);
				if (tmsNodes[i].ChildNodes.Count > 0)
					monNodes[i].AppendChild(tmsNodes[i]);
				if(evoNodes[i].ChildNodes.Count > 0)
					monNodes[i].AppendChild(evoNodes[i]);
			}

			XmlElement root = xml.CreateElement("monsters");
			foreach (XmlElement mon in monNodes)
				root.AppendChild(mon);
			xml.Schemas.Add(null, "monsters.xsd");
			xml.AppendChild(root);
			xml.Save("temp.xml");
			//Console.ReadKey();
		}

		static string[] ReadDefs(string filename)
		{
			string[] result = new string[1024];
			string[] lines = File.ReadAllLines(filename, Encoding.GetEncoding(1252));
			int i = 1;
			foreach (string l in lines)
			{
				string t = l.Trim();
				if (t.StartsWith("DEF("))
				{
					if (t.Contains('='))
					{
						i = int.Parse(t.Substring(t.IndexOf('=') + 1));
						t = t.Substring(1, t.IndexOf(')'));
					}
					t = t.Substring(t.IndexOf('(') + 1);
					result[i] = t.Substring(0, t.Length - 1);
					//result.Add(t.Substring(0, t.Length - 1));
					i++;
				}
			}
			return result;
		}
	}

	public static class Translation
	{
		private static string[] Table = new string[256];

		public static string CleanUp(string term)
		{
			string result = "";
			bool wantCap = true;
			foreach (char c in term)
			{
				if (wantCap && char.IsLetter(c))
				{
					result += char.ToUpper(c);
					wantCap = false;
				}
				else
					result += char.ToLower(c);
				if (char.IsPunctuation(c) && c != '\'' && c != '\\' || char.IsWhiteSpace(c))
					wantCap = true;
			}
			return result;
		}

		public static string ReadString(BinaryReader stream)
		{
			string r = "";
			char c = stream.ReadChar();
			while (c != 0xFF)
			{
				r += c;
				c = stream.ReadChar();
			}
			return r;
		}

		public static void LoadTable()
		{
			StreamReader file = new StreamReader("text.tbl", Encoding.Unicode);
			for (int i = 0; i < 256; i++)
				Table[i] = String.Format("\\x{0:X}", i);
			while (!file.EndOfStream)
			{
				string line = file.ReadLine();
				string idx = line.Substring(0, 2);
				string chr = line.Substring(3);
				int index = 0;
				int.TryParse(idx, System.Globalization.NumberStyles.HexNumber, null, out index);
				Table[index] = chr;
			}
			file.Close();
		}

		public static string ToAscii(string text)
		{
			if (Table[0] == null)
				LoadTable();

			string result = "";
			int i = 0;
			while (i < text.Length)
			{
				char thisChar = text[i];
				if (thisChar == '\xFC')
				{
					i++;
					switch ((byte)text[i])
					{
						case 1:
							result += "{ink:" + (byte)text[i + 1] + "}";
							i++;
							break;
						case 2:
							result += "{bg:" + (byte)text[i + 1] + "}";
							i++;
							break;
						case 3:
							result += "{shadow:" + (byte)text[i + 1] + "}";
							i++;
							break;
						case 4:
							result += "{clr:" + (byte)text[i + 1] + ":" + (byte)text[i + 2] + "}";
							i += 2;
							break;
						case 6:
							result += "{font:" + (byte)text[i + 1] + "}";
							i++;
							break;
						case 8:
							result += "{wait:" + (byte)text[i + 1] + "}";
							i++;
							break;
						case 9:
							result += "{key}";
							break;
						case 0xD:
							result += "{move:" + (byte)text[i + 1] + "}";
							i++;
							break;
						case 0x10:
							result += "{snd:" + (((byte)text[i + 2] << 8) + (byte)text[i + 1]) + "}";
							i += 2;
							break;
						case 0x15:
							result += "{jap}";
							break;
						case 0x16:
							result += "{usa}";
							break;
						case 0x17:
							result += "{pausesnd}";
							break;
						case 0x18:
							result += "{resumesnd}";
							break;
						default:
							result += "{cmd" + (byte)text[i + 1] + "}";
							break;
					}
				}
				else if (thisChar == '\xFD')
				{
					if ((byte)text[i + 1] < 0xD)
					{
						string[] vars =
						{
							"{NULL}", 
							"{RED}",
							"{var:2}",
							"{var:3}",
							"{var:4}",
							"{NULL2}",
							"{TERRY}",
							"{RUBY}",
							"{MAGMA}",
							"{AQUA}",
							"{MAXIE}",
							"{ARCHIE}",
							"{GROUDON}",
							"{KYOGRE}",
						};
						result += vars[(byte)text[i + 1]];
						i++;
					}
				}
				else
					result += Table[thisChar];
				i++;
			}
			return result;
		}

		public static string ToBytes(string text)
		{
			string result = "";
			int i = 0;
			while (i < text.Length)
			{
				char thisChar = text[i];
				result += string.Format("{0:X2} ", (int)thisChar);
				i++;
			}
			return result.Trim();
		}

	}
}
