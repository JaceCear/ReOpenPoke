using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace s2wav
{
	class s2wav
	{
		static void ConvertCry(int id)
		{
			string ID = string.Format("cry_{0:d3}", id);
			int HeaderPhase = 0;
			TextReader SFile = new StreamReader(File.Open(@"D:\devkitPro\fullthing\cries\" + ID + ".s", FileMode.Open));
			BinaryWriter WavFile = new BinaryWriter(File.Open(@"D:\devkitPro\fullthing\cries\" + ID + ".wav", FileMode.Create));
			WavFile.Write((int)0x46464952);
			WavFile.Write((int)0x204D);
			WavFile.Write((int)0x45564157);
			WavFile.Write((int)0x20746D66);
			WavFile.Write((int)0x10);
			WavFile.Write((int)0x10001);
			WavFile.Write((int)0x2B2A);
			WavFile.Write((int)0x2B2A);
			WavFile.Write((int)0x80001);
			WavFile.Write((int)0x61746164);

			while (true)
			{
				string ThisLin = SFile.ReadLine();
				if (ThisLin == null)
					break;
				ThisLin = ThisLin.Trim();
				string[] ThisLine = ThisLin.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
				if (ThisLine.Length == 0)
					continue;
				if ((ThisLine[0] == ID + ":" && HeaderPhase == 0) ||
					(ThisLine[0] == ".short" && HeaderPhase == 1) ||
					(ThisLine[0] == ".short" && HeaderPhase == 2) ||
					(ThisLine[0] == ".int" && HeaderPhase == 3) ||
					(ThisLine[0] == ".int" && HeaderPhase == 4))
					HeaderPhase++;
				else if (ThisLine[0] == ".int" && HeaderPhase == 5)
				{
					HeaderPhase++;
					WavFile.Write(int.Parse(ThisLine[1]));
				}
				else if (ThisLine[0] == ".byte" && HeaderPhase == 6)
				{
					string[] Bytes = ThisLine[1].Split(new char[] { ',' });
					foreach (string Byte in Bytes)
					{
						byte ThisByte = byte.Parse(Byte.Substring(2), System.Globalization.NumberStyles.HexNumber);
						WavFile.Write((byte)(ThisByte ^ 0x80));
					}
				}
			}
			SFile.Close();
			WavFile.Close();
		}

		static void Main(string[] args)
		{
			for (int id = 0; id < 412; id++)
			{
				Console.WriteLine("Converting #{0}...", id);
				ConvertCry(id);
			}
		}
	}
}
