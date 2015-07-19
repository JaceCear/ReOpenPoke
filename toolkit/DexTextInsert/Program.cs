using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DexTextInsert
{
	class Program
	{
		static void Main(string[] args)
		{
			File.Copy(@"data/pokedata_dex.c", @"data/pokedata_dex.c.bak", true);
			StreamReader srcFile = new StreamReader(File.Open(@"data/pokedata_dex.c.bak", FileMode.Open), Encoding.GetEncoding(1252));
			StreamReader inFile = new StreamReader(File.Open(@"dex_flavortext.txt", FileMode.Open), Encoding.GetEncoding(1252));
			StreamWriter outFile = new StreamWriter(File.Open(@"data/pokedata_dex.c", FileMode.Create), Encoding.GetEncoding(1252));
			inFile.ReadLine(); //skip first header
			while (true)
			{
				string line = srcFile.ReadLine();
				if (line == null)
					break;
				if (line.StartsWith("\t{"))
				{
					outFile.WriteLine(line); //write opening brace and species
					outFile.WriteLine(srcFile.ReadLine()); //write height/width
					string flavorSoFar = "";
					while (true)
					{
						line = inFile.ReadLine();
						if (line == "-")
							break;
						flavorSoFar += line + '\n';
					}
					flavorSoFar = flavorSoFar.Trim();
					flavorSoFar = flavorSoFar.Replace("Pokémon", "\"POKEMON\"");
					flavorSoFar = flavorSoFar.Replace("Poké", "\"POKE\"");
					flavorSoFar = "\t\t\"" + flavorSoFar.Replace("\n", "\\n\"\n\t\t\"") + "\",";
					outFile.WriteLine(flavorSoFar);
					flavorSoFar = "";
					while (true)
					{
						line = inFile.ReadLine();
						if (line.StartsWith("#"))
							break;
						flavorSoFar += line + '\n';
					}
					flavorSoFar = flavorSoFar.Trim();
					flavorSoFar = flavorSoFar.Replace("Pokémon", "\"POKEMON\"");
					flavorSoFar = flavorSoFar.Replace("Poké", "\"POKE\"");
					flavorSoFar = "\t\t\"" + flavorSoFar.Replace("\n", "\\n\"\n\t\t\"") + "\",";
					outFile.WriteLine(flavorSoFar);
					while (true)
					{
						line = srcFile.ReadLine();
						if (line.EndsWith("\","))
							break;
					}
					while (true)
					{
						line = srcFile.ReadLine();
						if (line.EndsWith("\","))
							break;
					}
					outFile.WriteLine(srcFile.ReadLine()); //write scale
					outFile.WriteLine(srcFile.ReadLine()); //write closing brace
				}
				else
				{
					outFile.WriteLine(line);
				}
			}
			outFile.Close();
			inFile.Close();
			srcFile.Close();
		}
	}
}
