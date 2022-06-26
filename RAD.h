#pragma once

namespace ProjectRAD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RAD
	/// </summary>
	public ref class RAD : public System::Windows::Forms::Form
	{
	public:
		RAD(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RAD()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_delete;

	private: System::Windows::Forms::Button^ button_change;




	private: System::Windows::Forms::Button^ button_add;







	private: System::Windows::Forms::ToolStripMenuItem^ DownloadDB;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Shifr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Denomination;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantity_pcs;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Notes;























	protected:


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DownloadDB = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_change = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Shifr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Denomination = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity_pcs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Notes = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->файлToolStripMenuItem,
					this->оПрограммеToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(908, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->DownloadDB });
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &RAD::File_ToolStripMenuItem_Click);
			// 
			// DownloadDB
			// 
			this->DownloadDB->Name = L"DownloadDB";
			this->DownloadDB->Size = System::Drawing::Size(198, 22);
			this->DownloadDB->Text = L"Загрузить базу данных";
			this->DownloadDB->Click += gcnew System::EventHandler(this, &RAD::DownloadDB_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &RAD::About_The_Program_ToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &RAD::Exit_ToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_change);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(88, 314);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &RAD::groupBox1_Enter);
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(6, 77);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(75, 23);
			this->button_delete->TabIndex = 2;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &RAD::button_delete_Click);
			// 
			// button_change
			// 
			this->button_change->Location = System::Drawing::Point(7, 48);
			this->button_change->Name = L"button_change";
			this->button_change->Size = System::Drawing::Size(75, 23);
			this->button_change->TabIndex = 1;
			this->button_change->Text = L"Изменить";
			this->button_change->UseVisualStyleBackColor = true;
			this->button_change->Click += gcnew System::EventHandler(this, &RAD::button_change_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(7, 19);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(75, 23);
			this->button_add->TabIndex = 0;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &RAD::button_add_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID, this->name,
					this->Shifr, this->Denomination, this->Quantity_pcs, this->Notes
			});
			this->dataGridView1->Location = System::Drawing::Point(106, 27);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(790, 314);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &RAD::dataGridView1_CellContentClick);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// name
			// 
			this->name->HeaderText = L"Наименование";
			this->name->Name = L"name";
			// 
			// Shifr
			// 
			this->Shifr->HeaderText = L"Шифр";
			this->Shifr->Name = L"Shifr";
			// 
			// Denomination
			// 
			this->Denomination->HeaderText = L"Номинал";
			this->Denomination->Name = L"Denomination";
			// 
			// Quantity_pcs
			// 
			this->Quantity_pcs->HeaderText = L"Количество, шт";
			this->Quantity_pcs->Name = L"Quantity_pcs";
			// 
			// Notes
			// 
			this->Notes->HeaderText = L"Примечания";
			this->Notes->Name = L"Notes";
			// 
			// RAD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(908, 341);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"RAD";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RAD";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		private: System::Void File_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button_change_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void About_The_Program_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Exit_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e);
		private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void DownloadDB_Click(System::Object^ sender, System::EventArgs^ e);
		


};
}
