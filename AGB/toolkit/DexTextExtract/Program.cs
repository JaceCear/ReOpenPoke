using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DexText
{
	class Program
	{
		static void Main(string[] args)
		{
			/* GROUND RULES
			 * ------------
			 * We expect pokedata_dex.c to have one include line, and that there are only three full string literals per Pokémon:
			 * 1) the species name
			 * 2) the first page of flavor text
			 * 3) the second page
			 * The problem is in that the flavor text is split up into at most three seperate string literals, concatenated by
			 * the compiler into one. We should imitate this behavior when dumping the texts.
			 * The nice thing is that all Pokémon are equal in general line order:
			 * 1) Skip the first two lines (opening brace, species and height/weight)
			 * 2) Read up to three lines or until one ends with ','
			 * 3) Repeat once
			 * 4) Skip the last lines (scale and closing brace)
			 */
			
			StreamReader inFile = new StreamReader(File.Open(@"data/pokedata_dex.c", FileMode.Open), Encoding.GetEncoding(1252));
			StreamWriter outFile = new StreamWriter(File.Open(@"dex_flavortext.txt", FileMode.Create), Encoding.GetEncoding(1252));

			//Skip until we find the opening brace.
			string line = inFile.ReadLine();
			while (line != "{")
				line = inFile.ReadLine();
			//Now, ENTER THE LOOP!
			while (line != "}")
			{
				line = inFile.ReadLine();
				string species = line.Substring(line.LastIndexOf(',') + 2);
				inFile.ReadLine(); //Skip height/weight data
				//Start reading first page of flavor text...
				string flavorSoFar = "";
				do
				{
					line = inFile.ReadLine();
					if (line == null)
						break;
					int firstQuote = line.IndexOf('"');
					int lastQuote = line.LastIndexOf('"');
					flavorSoFar += line.Substring(firstQuote + 1, lastQuote - 1 - firstQuote);
				} while (!line.EndsWith(","));
				if (line == null)
					break;
				flavorSoFar += "\n-\n";
				//Read the second page...
				do
				{
					line = inFile.ReadLine();
					int firstQuote = line.IndexOf('"');
					int lastQuote = line.LastIndexOf('"');
					flavorSoFar += line.Substring(firstQuote + 1, lastQuote - 1 - firstQuote);
				} while (!line.EndsWith(","));

				//Mangle the text a bit...
				flavorSoFar = flavorSoFar.Replace("\\n", "\n");
				flavorSoFar = flavorSoFar.Replace("\"POKEMON\"", "Pokémon");
				outFile.WriteLine("# " + species.ToUpper());
				outFile.WriteLine(flavorSoFar);

				inFile.ReadLine(); //Skip scales
				inFile.ReadLine(); //Skip closing brace
			}
			inFile.Close();
			outFile.Close();
		}
	}
}
