using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace UpdateMonPics
{
	class UpdateMonPics
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Creating backup copy...");
			File.Copy("data/pokedata_images.c", "data/pokedata_images.c.bak", true);
			Console.WriteLine("Working...");
			TextReader controls = new StreamReader(File.Open("pokepics.txt", FileMode.Open));
			TextWriter output = new StreamWriter(File.Open("data/pokedata_images.c", FileMode.Create));
			string c = "";
			bool FirstBlock = true;
			output.WriteLine("#include \"../openpoke.h\"");
			while ((c = controls.ReadLine()) != "")
			{
				string[] parts = c.Trim().Split(new char[] {' '});

				if (parts[0] == "Block")
				{
					if (!FirstBlock)
						output.WriteLine("};");
					output.WriteLine();
					output.WriteLine("const unsigned short * const {0}[] =", parts[1]);
					output.WriteLine("{");
					FirstBlock = false;
				}
				if (parts[0] == "Part")
				{
					string format = "";
					int rangeStart = 0;
					int rangeEnd = 0;
					string c2 = "";
					while ((c2 = controls.ReadLine()) != "")
					{
						string[] parts2 = c2.Trim().Split(new char[] { ' ' });
						if (parts2[0] == "Format")
							format = parts2[1];
						if (parts2[0] == "Range")
						{
							rangeStart = int.Parse(parts2[1]);
							rangeEnd = int.Parse(parts2[2]);
							for(int i = rangeStart; i <= rangeEnd; i++)
								output.WriteLine("\t" + format + ",", i);
							output.WriteLine();
							break;
						}
					}
				}
				if (parts[0] == "Single")
				{
					string c2 = controls.ReadLine().Trim();
					output.WriteLine("\t" + c2 + ",");
					output.WriteLine();
				}
				if (parts[0] == "Unown")
				{
					string c2 = controls.ReadLine().Trim();
					for (int i = 'b'; i <= 'z'; i++)
						output.WriteLine("\t" + c2 + ",", (char)i);
					output.WriteLine("\t" + c2 + ",", "question");
					output.WriteLine("\t" + c2 + ",", "exclamation");
					output.WriteLine();
				}
			}
			output.WriteLine("};");
			output.Close();
		}
	}
}
