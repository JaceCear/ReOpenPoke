using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TrainerGenerator
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		#region Species list
		private void lstSpecies_SelectedIndexChanged(object sender, EventArgs e)
		{
			btnRemoveSpecies.Enabled = true;
		}

		private void btnRemoveSpecies_Click(object sender, EventArgs e)
		{
			int oldIndex = lstSpecies.SelectedIndex;
			lstSpecies.Items.RemoveAt(oldIndex);
			if (oldIndex >= lstSpecies.Items.Count)
				oldIndex = lstSpecies.Items.Count - 1;
			lstSpecies.SelectedIndex = oldIndex;
			btnRemoveSpecies.Enabled = (oldIndex > -1);
		}

		private void txtSpecies_TextChanged(object sender, EventArgs e)
		{
			btnAddSpecies.Enabled = !string.IsNullOrEmpty(txtSpecies.Text.Trim());
		}

		private void txtSpecies_KeyUp(object sender, KeyEventArgs e)
		{
			if (e.KeyCode == Keys.Return)
			{
				if (!string.IsNullOrEmpty(txtSpecies.Text.Trim()))
				{
					lstSpecies.Items.Add(txtSpecies.Text.Trim());
					txtSpecies.Text = "";
					btnAddSpecies.Enabled = false;
				}
				e.Handled = true;
			}
		}

		private void btnAddSpecies_Click(object sender, EventArgs e)
		{
			if(!string.IsNullOrEmpty(txtSpecies.Text.Trim()))
				lstSpecies.Items.Add(txtSpecies.Text.Trim());
		}
		#endregion

		#region Images list
		private void lstImages_SelectedIndexChanged(object sender, EventArgs e)
		{
			btnRemoveImage.Enabled = true;
		}

		private void btnRemoveImage_Click(object sender, EventArgs e)
		{
			int oldIndex = lstImages.SelectedIndex;
			lstImages.Items.RemoveAt(oldIndex);
			if (oldIndex >= lstImages.Items.Count)
				oldIndex = lstImages.Items.Count - 1;
			lstImages.SelectedIndex = oldIndex;
			btnRemoveImage.Enabled = (oldIndex > -1);
		}

		private void txtImages_TextChanged(object sender, EventArgs e)
		{
			btnAddImage.Enabled = !string.IsNullOrEmpty(txtImages.Text.Trim());
		}

		private void txtImages_KeyUp(object sender, KeyEventArgs e)
		{
			if (e.KeyCode == Keys.Return)
			{
				if (!string.IsNullOrEmpty(txtImages.Text.Trim()))
				{
					lstImages.Items.Add(txtImages.Text.Trim());
					txtImages.Text = "";
					btnAddImage.Enabled = false;
				}
				e.Handled = true;
			}
		}

		private void btnAddImage_Click(object sender, EventArgs e)
		{
			if(!string.IsNullOrEmpty(txtImages.Text.Trim()))
				lstImages.Items.Add(txtImages.Text.Trim());
		}
		#endregion

		private void txtLevel_Validating(object sender, CancelEventArgs e)
		{
			int r;
			TextBox t = (TextBox)sender;
			if (int.TryParse(t.Text, out r))
			{
				t.Text = r.ToString();
			}
			else
			{
				MessageBox.Show("Only integer values please.");
				e.Cancel = true;
			}
		}

		private void btnRoll_Click(object sender, EventArgs e)
		{
			Application.UseWaitCursor = true;
			if (lstSpecies.Items.Count == 0 || lstImages.Items.Count == 0)
			{
				txtResult.Text = "You must add some images and species to work with.";
				return;
			}
			Random r = new Random();
			string result = "";
			pbrRolling.Maximum = 40;
			if (chkXML.Checked)
			{
				for (int i = 1; i <= 40; i++)
				{
					result += String.Format("<trainer class=\"{0}\" name=\"{1}\" image=\"{2}\">\r\n", txtClass.Text, txtName.Text, lstImages.Items[r.Next(lstImages.Items.Count)]);
					result += "\t<party>\r\n";
					int numMon = r.Next(2, 5);
					int lvlMin = r.Next(int.Parse(txtLevelMin.Text), int.Parse(txtLevelMax.Text));
					int lvlMax = lvlMin + r.Next(3);
					for (int j = 1; j <= numMon; j++)
						result += String.Format("\t\t<mon id=\"{2}\" level=\"{1}\" />\r\n", j, r.Next(lvlMin, lvlMax), lstSpecies.Items[r.Next(lstSpecies.Items.Count)]);
					result += "\t</party>\r\n";
					result += "</trainer>\r\n";
					pbrRolling.Value = i;
				}
			}
			else
			{
				for (int i = 1; i <= 40; i++)
				{
					result += String.Format("{0} {1}, {2}\r\n", txtClass.Text, txtName.Text, lstImages.Items[r.Next(lstImages.Items.Count)]);
					int numMon = r.Next(2, 5);
					int lvlMin = r.Next(int.Parse(txtLevelMin.Text), int.Parse(txtLevelMax.Text));
					int lvlMax = lvlMin + r.Next(3);
					for (int j = 1; j <= numMon; j++)
						result += String.Format(" {0}. Lv.{1} {2}\r\n", j, r.Next(lvlMin, lvlMax), lstSpecies.Items[r.Next(lstSpecies.Items.Count)]);
					result += "\r\n";
					pbrRolling.Value = i;
				}
			}
			txtResult.Text = result;
			Application.UseWaitCursor = false;
		}

		private void btnCopy_Click(object sender, EventArgs e)
		{
			Clipboard.SetText(txtResult.Text);
		}
	}
}
