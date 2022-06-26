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
	//����������� � ���� ������
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=RADBase.mdb";//������ �����������
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//���������� ������� � ���� ������
	dbConnection->Open();//�������� ����������
	String^ query = "SELECT * FROM [RADBase]";//������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);//�������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//���������� ������

	//��������� ������
	if (dbReader->HasRows == false) 
	{
		MessageBox::Show("������ ���������� ������!", "������!");
	}
	else 
	{
		//���������� ������ � ������� �����
		while (dbReader->Read()) 
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Shifr"], dbReader["Denomination"], dbReader["Quantity_pcs"], dbReader["Notes"]);
		}
	}

	//�������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}


System::Void ProjectRAD::RAD::About_The_Program_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������ ��������� ����������� ��� ����� ���������������� �����������,\t� ��� �� ��� �������� �������� �� ���������� �� ������");
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

