#include "RAD.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ProjectRAD::RAD form;
	Application::Run(% form);
}

System::Void ProjectRAD::RAD::File_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	return System::Void();
}

System::Void ProjectRAD::RAD::DownloadDB_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Подключение к базе данных
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=RADBase.mdb";//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполнение запроса к базе данных
	dbConnection->Open();//открытие соеденения
	String^ query = "SELECT * FROM [RADBase]";//запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//считывание данных

	//Проверяем данные
	if (dbReader->HasRows == false) 
	{
		MessageBox::Show("Ошибка считывания данных!", "Ошибка!");
	}
	else 
	{
		//Заполнение данных в таблицу формы
		while (dbReader->Read()) 
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Shifr"], dbReader["Denomination"], dbReader["Quantity_pcs"], dbReader["Notes"]);
		}
	}

	//Закрытие соеденения
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}


System::Void ProjectRAD::RAD::About_The_Program_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Данная программа ипользуется для учёта радиоэлектронных компонентов,\tа так же для создания шаблонов их количества на платах");
	return System::Void();
}

System::Void ProjectRAD::RAD::Exit_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void ProjectRAD::RAD::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ProjectRAD::RAD::button_change_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ProjectRAD::RAD::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ProjectRAD::RAD::groupBox1_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ProjectRAD::RAD::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	return System::Void();
}

