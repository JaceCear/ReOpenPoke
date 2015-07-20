using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Drawing;

namespace UpdateSprites
{
	class SpriteSCData
	{
		public string spriteName = "";
		public int size = 0;
		public int color = 0;
		public SpriteSCData(string n, int s, int c)
		{
			spriteName = n;
			size = s;
			color = c;
		}
	}

	class UpdateSprites
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Creating backups...");
			File.Copy("data/spritedata.h", "data/spritedata.h.bak", true);
			File.Copy("data/spritedata.c", "data/spritedata.c.bak", true);

			Console.WriteLine("Retrieving sprite list...");
			string[] spritefiles = Directory.GetFiles("ow_sprites", "*.png");
			for (int i = 0; i < spritefiles.Length; i++)
				spritefiles[i] = Path.GetFileNameWithoutExtension(spritefiles[i]);

			Console.WriteLine("Loading sizes and colors...");
			List<SpriteSCData> SpriteColorData = new List<SpriteSCData>();
			string[] rawColorData = File.ReadAllLines("sprites.txt");
			foreach (string r in rawColorData)
			{
				string[] p = r.Split(new char[] { '\t' });
				SpriteColorData.Add(new SpriteSCData(p[0], int.Parse(p[2]), int.Parse(p[1])));
			}

			TextWriter sprdatH = new StreamWriter(File.Open("data/spritedata.h", FileMode.Create), Encoding.ASCII);

			Console.WriteLine("Writing #defines...");
			for (int i = 0; i < spritefiles.Length; i++)
				sprdatH.WriteLine("#define spr{0} {1}", SpriteColorData[i].spriteName.ToUpper(), i + 1);
				//sprdatH.WriteLine("#define spr{0} {1}", spritefiles[i].ToUpper(), i + 1);
			sprdatH.WriteLine();

			Console.WriteLine("Writing externs...");
			for (int i = 0; i < spritefiles.Length; i++)
				sprdatH.WriteLine("extern const unsigned short {0}Tiles[];", spritefiles[i]);
			sprdatH.Close();

			TextWriter sprdatC = new StreamWriter(File.Open("data/spritedata.c", FileMode.Create), Encoding.ASCII);

			Console.WriteLine("Writing spritedata...");
			sprdatC.WriteLine("#include \"../openpoke.h\"");
			sprdatC.WriteLine();
			sprdatC.WriteLine("const aSprite Sprites[] =");
			sprdatC.WriteLine("{");
			sprdatC.WriteLine("\t{ 0, 0, 0 },");
			foreach (SpriteSCData d in SpriteColorData)
			{
				foreach (string s in spritefiles)
				{
					if (s.ToLower() == d.spriteName.ToLower())
					{
						string f = d.spriteName + "Tiles,";
						sprdatC.WriteLine("\t{{ {0} {1}, {2} }},", f.PadRight(24), d.color, d.size);
					}
				}
			}
			sprdatC.WriteLine("};");
			sprdatC.Close();

			Console.WriteLine("Creating map editor sheet...");
			Bitmap img = new Bitmap(spritefiles.Length * 32, 32);
			Graphics gfx = Graphics.FromImage(img);
			gfx.Clear(Color.Transparent);
			int l = 32;
			foreach (SpriteSCData p in SpriteColorData)
			{
				string f = p.spriteName.Remove(p.spriteName.IndexOf("Tiles"));
				Bitmap spr = (Bitmap)Bitmap.FromFile("ow_sprites/" + f + ".png");
				switch (p.size)
				{
					case 0: //Normal
						gfx.DrawImageUnscaled(spr, l + 8, 0, 16, 32);
						break;
					case 1: //Small
						gfx.DrawImageUnscaled(spr, l + 8, 16, 16, 16);
						break;
					case 2: //Large
						gfx.DrawImageUnscaled(spr, l, 0, 32, 32);
						break;
				}
				l += 32;
			}
			img.Save("mapedit/sprites.png", System.Drawing.Imaging.ImageFormat.Png);

			TextWriter mapList = new StreamWriter(File.Open("mapedit/spritelist.txt", FileMode.Create), Encoding.ASCII);

			Console.WriteLine("Writing map editor list...");
			foreach (string s in spritefiles)
				mapList.WriteLine(s.ToUpper());
			mapList.Close();
		}
	}
}
