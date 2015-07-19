namespace TrainerGenerator
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.btnRemoveSpecies = new System.Windows.Forms.Button();
			this.btnAddSpecies = new System.Windows.Forms.Button();
			this.txtSpecies = new System.Windows.Forms.TextBox();
			this.lstSpecies = new System.Windows.Forms.ListBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.btnRemoveImage = new System.Windows.Forms.Button();
			this.btnAddImage = new System.Windows.Forms.Button();
			this.txtImages = new System.Windows.Forms.TextBox();
			this.lstImages = new System.Windows.Forms.ListBox();
			this.txtClass = new System.Windows.Forms.TextBox();
			this.txtName = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.txtLevelMin = new System.Windows.Forms.TextBox();
			this.txtLevelMax = new System.Windows.Forms.TextBox();
			this.txtResult = new System.Windows.Forms.TextBox();
			this.btnRoll = new System.Windows.Forms.Button();
			this.chkXML = new System.Windows.Forms.CheckBox();
			this.btnCopy = new System.Windows.Forms.Button();
			this.pbrRolling = new System.Windows.Forms.ProgressBar();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)));
			this.groupBox1.Controls.Add(this.btnRemoveSpecies);
			this.groupBox1.Controls.Add(this.btnAddSpecies);
			this.groupBox1.Controls.Add(this.txtSpecies);
			this.groupBox1.Controls.Add(this.lstSpecies);
			this.groupBox1.Location = new System.Drawing.Point(184, 88);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(168, 240);
			this.groupBox1.TabIndex = 12;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Species";
			// 
			// btnRemoveSpecies
			// 
			this.btnRemoveSpecies.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnRemoveSpecies.Enabled = false;
			this.btnRemoveSpecies.Location = new System.Drawing.Point(88, 208);
			this.btnRemoveSpecies.Name = "btnRemoveSpecies";
			this.btnRemoveSpecies.Size = new System.Drawing.Size(72, 24);
			this.btnRemoveSpecies.TabIndex = 16;
			this.btnRemoveSpecies.Text = "Remove";
			this.btnRemoveSpecies.UseVisualStyleBackColor = true;
			this.btnRemoveSpecies.Click += new System.EventHandler(this.btnRemoveSpecies_Click);
			// 
			// btnAddSpecies
			// 
			this.btnAddSpecies.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnAddSpecies.Enabled = false;
			this.btnAddSpecies.Location = new System.Drawing.Point(8, 208);
			this.btnAddSpecies.Name = "btnAddSpecies";
			this.btnAddSpecies.Size = new System.Drawing.Size(72, 24);
			this.btnAddSpecies.TabIndex = 15;
			this.btnAddSpecies.Text = "Add";
			this.btnAddSpecies.UseVisualStyleBackColor = true;
			this.btnAddSpecies.Click += new System.EventHandler(this.btnAddSpecies_Click);
			// 
			// txtSpecies
			// 
			this.txtSpecies.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.txtSpecies.Location = new System.Drawing.Point(8, 184);
			this.txtSpecies.Name = "txtSpecies";
			this.txtSpecies.Size = new System.Drawing.Size(152, 22);
			this.txtSpecies.TabIndex = 14;
			this.txtSpecies.TextChanged += new System.EventHandler(this.txtSpecies_TextChanged);
			this.txtSpecies.KeyUp += new System.Windows.Forms.KeyEventHandler(this.txtSpecies_KeyUp);
			// 
			// lstSpecies
			// 
			this.lstSpecies.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)));
			this.lstSpecies.FormattingEnabled = true;
			this.lstSpecies.IntegralHeight = false;
			this.lstSpecies.Items.AddRange(new object[] {
            "Zubat",
            "Zubat",
            "Zubat",
            "Ekans",
            "Ekans",
            "Ekans",
            "Koffing",
            "Koffing",
            "Koffing",
            "Rattata",
            "Rattata",
            "Rattata",
            "Sandshrew",
            "Machop",
            "Drowzee",
            "Raticate",
            "Grimer",
            "Hitmonlee"});
			this.lstSpecies.Location = new System.Drawing.Point(8, 16);
			this.lstSpecies.Name = "lstSpecies";
			this.lstSpecies.Size = new System.Drawing.Size(152, 160);
			this.lstSpecies.TabIndex = 13;
			this.lstSpecies.SelectedIndexChanged += new System.EventHandler(this.lstSpecies_SelectedIndexChanged);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(8, 8);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(69, 13);
			this.label1.TabIndex = 0;
			this.label1.Text = "Trainer class";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(8, 32);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(36, 13);
			this.label2.TabIndex = 2;
			this.label2.Text = "Name";
			// 
			// groupBox2
			// 
			this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)));
			this.groupBox2.Controls.Add(this.btnRemoveImage);
			this.groupBox2.Controls.Add(this.btnAddImage);
			this.groupBox2.Controls.Add(this.txtImages);
			this.groupBox2.Controls.Add(this.lstImages);
			this.groupBox2.Location = new System.Drawing.Point(8, 88);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(168, 240);
			this.groupBox2.TabIndex = 7;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Images";
			// 
			// btnRemoveImage
			// 
			this.btnRemoveImage.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnRemoveImage.Enabled = false;
			this.btnRemoveImage.Location = new System.Drawing.Point(88, 208);
			this.btnRemoveImage.Name = "btnRemoveImage";
			this.btnRemoveImage.Size = new System.Drawing.Size(72, 24);
			this.btnRemoveImage.TabIndex = 11;
			this.btnRemoveImage.Text = "Remove";
			this.btnRemoveImage.UseVisualStyleBackColor = true;
			this.btnRemoveImage.Click += new System.EventHandler(this.btnRemoveImage_Click);
			// 
			// btnAddImage
			// 
			this.btnAddImage.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.btnAddImage.Enabled = false;
			this.btnAddImage.Location = new System.Drawing.Point(8, 208);
			this.btnAddImage.Name = "btnAddImage";
			this.btnAddImage.Size = new System.Drawing.Size(72, 24);
			this.btnAddImage.TabIndex = 10;
			this.btnAddImage.Text = "Add";
			this.btnAddImage.UseVisualStyleBackColor = true;
			this.btnAddImage.Click += new System.EventHandler(this.btnAddImage_Click);
			// 
			// txtImages
			// 
			this.txtImages.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.txtImages.Location = new System.Drawing.Point(8, 184);
			this.txtImages.Name = "txtImages";
			this.txtImages.Size = new System.Drawing.Size(152, 22);
			this.txtImages.TabIndex = 9;
			this.txtImages.TextChanged += new System.EventHandler(this.txtImages_TextChanged);
			this.txtImages.KeyUp += new System.Windows.Forms.KeyEventHandler(this.txtImages_KeyUp);
			// 
			// lstImages
			// 
			this.lstImages.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)));
			this.lstImages.FormattingEnabled = true;
			this.lstImages.IntegralHeight = false;
			this.lstImages.Items.AddRange(new object[] {
            "RocketGruntA",
            "RocketGruntB"});
			this.lstImages.Location = new System.Drawing.Point(8, 16);
			this.lstImages.Name = "lstImages";
			this.lstImages.Size = new System.Drawing.Size(152, 160);
			this.lstImages.TabIndex = 8;
			this.lstImages.SelectedIndexChanged += new System.EventHandler(this.lstImages_SelectedIndexChanged);
			// 
			// txtClass
			// 
			this.txtClass.Location = new System.Drawing.Point(96, 8);
			this.txtClass.Name = "txtClass";
			this.txtClass.Size = new System.Drawing.Size(136, 22);
			this.txtClass.TabIndex = 1;
			this.txtClass.Text = "TeamRocket";
			// 
			// txtName
			// 
			this.txtName.Location = new System.Drawing.Point(96, 32);
			this.txtName.Name = "txtName";
			this.txtName.Size = new System.Drawing.Size(136, 22);
			this.txtName.TabIndex = 3;
			this.txtName.Text = "Grunt";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(8, 56);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(65, 13);
			this.label3.TabIndex = 4;
			this.label3.Text = "Level range";
			// 
			// txtLevelMin
			// 
			this.txtLevelMin.Location = new System.Drawing.Point(96, 56);
			this.txtLevelMin.Name = "txtLevelMin";
			this.txtLevelMin.Size = new System.Drawing.Size(64, 22);
			this.txtLevelMin.TabIndex = 5;
			this.txtLevelMin.Text = "10";
			this.txtLevelMin.Validating += new System.ComponentModel.CancelEventHandler(this.txtLevel_Validating);
			// 
			// txtLevelMax
			// 
			this.txtLevelMax.Location = new System.Drawing.Point(168, 56);
			this.txtLevelMax.Name = "txtLevelMax";
			this.txtLevelMax.Size = new System.Drawing.Size(64, 22);
			this.txtLevelMax.TabIndex = 6;
			this.txtLevelMax.Text = "20";
			this.txtLevelMax.Validating += new System.ComponentModel.CancelEventHandler(this.txtLevel_Validating);
			// 
			// txtResult
			// 
			this.txtResult.AcceptsReturn = true;
			this.txtResult.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtResult.Location = new System.Drawing.Point(360, 40);
			this.txtResult.Multiline = true;
			this.txtResult.Name = "txtResult";
			this.txtResult.ReadOnly = true;
			this.txtResult.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.txtResult.Size = new System.Drawing.Size(456, 288);
			this.txtResult.TabIndex = 20;
			// 
			// btnRoll
			// 
			this.btnRoll.Location = new System.Drawing.Point(360, 8);
			this.btnRoll.Name = "btnRoll";
			this.btnRoll.Size = new System.Drawing.Size(88, 24);
			this.btnRoll.TabIndex = 18;
			this.btnRoll.Text = "Roll \'em!";
			this.btnRoll.UseVisualStyleBackColor = true;
			this.btnRoll.Click += new System.EventHandler(this.btnRoll_Click);
			// 
			// chkXML
			// 
			this.chkXML.AutoSize = true;
			this.chkXML.Checked = true;
			this.chkXML.CheckState = System.Windows.Forms.CheckState.Checked;
			this.chkXML.Location = new System.Drawing.Point(264, 8);
			this.chkXML.Name = "chkXML";
			this.chkXML.Size = new System.Drawing.Size(64, 17);
			this.chkXML.TabIndex = 17;
			this.chkXML.Text = "As XML";
			this.chkXML.UseVisualStyleBackColor = true;
			// 
			// btnCopy
			// 
			this.btnCopy.Location = new System.Drawing.Point(456, 8);
			this.btnCopy.Name = "btnCopy";
			this.btnCopy.Size = new System.Drawing.Size(88, 24);
			this.btnCopy.TabIndex = 19;
			this.btnCopy.Text = "Copy";
			this.btnCopy.UseVisualStyleBackColor = true;
			this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
			// 
			// pbrRolling
			// 
			this.pbrRolling.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.pbrRolling.Location = new System.Drawing.Point(552, 8);
			this.pbrRolling.Name = "pbrRolling";
			this.pbrRolling.Size = new System.Drawing.Size(264, 16);
			this.pbrRolling.TabIndex = 21;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(824, 336);
			this.Controls.Add(this.pbrRolling);
			this.Controls.Add(this.btnCopy);
			this.Controls.Add(this.chkXML);
			this.Controls.Add(this.btnRoll);
			this.Controls.Add(this.txtResult);
			this.Controls.Add(this.txtLevelMax);
			this.Controls.Add(this.txtLevelMin);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.txtName);
			this.Controls.Add(this.txtClass);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.groupBox1);
			this.Font = new System.Drawing.Font("Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MinimumSize = new System.Drawing.Size(608, 236);
			this.Name = "Form1";
			this.Text = "OpenPoké Mook Maker";
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Button btnRemoveSpecies;
		private System.Windows.Forms.Button btnAddSpecies;
		private System.Windows.Forms.TextBox txtSpecies;
		private System.Windows.Forms.ListBox lstSpecies;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.Button btnRemoveImage;
		private System.Windows.Forms.Button btnAddImage;
		private System.Windows.Forms.TextBox txtImages;
		private System.Windows.Forms.ListBox lstImages;
		private System.Windows.Forms.TextBox txtClass;
		private System.Windows.Forms.TextBox txtName;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox txtLevelMin;
		private System.Windows.Forms.TextBox txtLevelMax;
		private System.Windows.Forms.TextBox txtResult;
		private System.Windows.Forms.Button btnRoll;
		private System.Windows.Forms.CheckBox chkXML;
		private System.Windows.Forms.Button btnCopy;
		private System.Windows.Forms.ProgressBar pbrRolling;
	}
}

