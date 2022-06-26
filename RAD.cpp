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
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=RADBase.mdb";					//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполнение запроса к базе данных
	dbConnection->Open();																					//Открытие соеденения
	String^ query = "SELECT * FROM [RADBase]";																//Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);										//Команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();													//Считывание данных

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
	//Выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	//Узанаем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr) 
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Ститывание данных
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Shifr = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Denomination = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Quantity_pcs = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ Notes = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	
	//Подключение к базе данных
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=RADBase.mdb";																				//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполнение запроса к базе данных 
	dbConnection->Open();																																				//Открытие соеденения
	String^ query = "INSERT INTO [RADBase] VALUES (" + ID + ",'" + Name + "', '" + Shifr + "', '" + Denomination + "', " + Quantity_pcs + ", '" + Notes + "')";		//Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);																									//Команда

	//Выполнение запроса
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные добавлены!", "Готово!");

	//Закрытие соединения к базе данных
	dbConnection->Close();

	return System::Void();
}

System::Void ProjectRAD::RAD::button_change_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1) 
	{
		MessageBox::Show("Выберите одну строку для изменения!", "Внимание!");
		return;
	}

	//Узанаем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Ститывание данных
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Shifr = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ Denomination = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ Quantity_pcs = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ Notes = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

	//Подключение к базе данных
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=RADBase.mdb";																																//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполнение запроса к базе данных 
	dbConnection->Open();																																																//Открытие соеденения
	String^ query = "UPDATE [RADBase] SET Name= '" + Name + "', Shifr =  '" + Shifr + "', Denomination = '" + Denomination + "', Quantity_pcs = " + Quantity_pcs + ", Notes = '" + Notes + "' WHERE id = " + ID;		//Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//Выполнение запроса
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else
		MessageBox::Show("Данные изменены!", "Готово!");

	//Закрытие соединения к базе данных
	dbConnection->Close();

	return System::Void();
}

System::Void ProjectRAD::RAD::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор нужной строки для добавления
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для удаления!", "Внимание!");
		return;
	}

	//Узанаем индекс выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	//Ститывание данных
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	
	//Подключение к базе данных
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=RADBase.mdb";		//Строка подключения
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Выполнение запроса к базе данных 
	dbConnection->Open();																		//Открытие соеденения
	String^ query = "DELETE FROM [RADBase] WHERE id = " + ID;									//Запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//Выполняем запрос
	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	else 
	{
		MessageBox::Show("Данные удалены!", "Готово!");
		dataGridView1->Rows->RemoveAt(index);													//Удаление строки из таблицы формы
	}

	//Закрытие соединения к базе данных
	dbConnection->Close();

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

