using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TextHelper
{
	public partial class Form1 : Form
	{
		Bitmap font, back;
		Bitmap backbuffer;
		Graphics graphics;

		public Form1()
		{
			InitializeComponent();
			font = new Bitmap("font.png");
			back = new Bitmap("dial.png");
			CountNewlines();
		}

		private void textBox1_TextChanged(object sender, EventArgs e)
		{
			CountNewlines();
		}

		private void CountNewlines()
		{
			int nls = 1;
			for(int i = 0; i < textBox1.Text.Length; i++)
				if(textBox1.Text[i] == '\n')
					nls++;
			DrawText(nls * 14);
		}

		private void DrawText(int height)
		{
			byte[] fontWesternWidths =
			{
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				3,6,7,8,8,8,8,3,5,5,8,8,5,6,5,6, //  to /
				6,6,6,6,6,6,6,6,6,6,5,5,8,8,8,6, //0 to ?
				0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6, //@ to O
				6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8, //P to _
				3,6,6,6,6,6,6,6,6,4,6,5,5,6,5,6, //' to o
				6,6,5,5,5,6,6,6,6,6,6,7,4,7,7,6, //p to house
				8,8,8,8,8,6,8,8,8,8,7,7,8,8,8,8, //> to 9
				8,3,3,6,6,5,6,8,8,8,8,8,8,8,8,8, //_ to re
				4,6,6,8,8,8,8,2,2,8,6,2,2,0,8,8, //  to ¯
				8,8,8,8,8,8,8,5,0,4,6,0,8,8,8,6, //^ to ¿
				6,6,6,6,6,6,8,6,6,6,6,6,6,6,6,6, //À to Ï
				7,6,6,6,6,8,6,8,6,6,6,6,6,6,5,6, //Ð to ß
				6,6,6,6,6,6,8,6,6,6,6,6,6,6,6,6, //à to ï
				6,6,6,6,6,6,6,8,8,6,6,6,6,6,6,6, //ð to
			};
			if (height < 28)
				height = 28;
			backbuffer = new Bitmap(240, height);
			graphics = Graphics.FromImage(backbuffer);
			graphics.Clear(Color.Gray);

			int margin = 16;

			Rectangle src = new Rectangle(0, 0, 240, 32);
			Rectangle dst = new Rectangle(0, -8, 240, height + 16);
			graphics.DrawImage(back, dst, src, GraphicsUnit.Pixel);

			int tx = margin, ty = 0;
			string text = textBox1.Text.Replace("\r\n", "\n");
			for (int i = 0; i < text.Length; i++)
			{
				int c = (int)text[i];
				if (c == (int)'\n')
				{
					tx = margin;
					ty += 14;
				}
				if (c < 32)
					continue;
				int ox = (c % 16) * 8;
				int oy = (c / 16) * 16;
				src = new Rectangle(ox, oy, fontWesternWidths[c], 14);
				dst = new Rectangle(tx, ty, fontWesternWidths[c], 14);
				graphics.DrawImage(font, dst, src, GraphicsUnit.Pixel);
				tx += fontWesternWidths[c];
			}

			pictureBox1.Image = backbuffer;
		}

		private void checkBox1_CheckedChanged(object sender, EventArgs e)
		{
			CountNewlines();
		}
	}
}
