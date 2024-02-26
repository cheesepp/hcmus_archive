#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

#define SIZE 2000

struct Company
{
	string name;
	string tax_code;
	string address;
};

Company readCompany(string line_info)
{
	Company company;
	stringstream s(line_info);
	string buffer;
	vector<string> info;
	for (int i = 0; i < 3; i++)
	{
		getline(s, buffer, '|');
		info.push_back(buffer);
	}
	company.name = info[0];
	company.tax_code = info[1];
	company.address = info[2];
	return company;
}

vector<Company> readCompanyList(string file_name)
{
	vector<Company> companyList;
	ifstream in(file_name);
	if (in.is_open())
	{
		string line_info;
		getline(in, line_info, '\n');
		while (!in.eof())
		{
			getline(in, line_info, '\n');
			Company company = readCompany(line_info);
			companyList.push_back(company);
		}
	}
	else
	{
		cout << "Khong mo duoc file!" << endl;
	}
	return companyList;
}

long long HashString(string company_name)
{
	unsigned long long hashResult = 0; 
	string len = company_name.length() <= 20 ? company_name : company_name.substr(company_name.length()-20);
	long long m = pow(10, 9) + 9;
	for (int i = 0; i < len.length(); i++)
	{
		int asciiChar = (int)company_name[i];
		if (i >= 10)
		{
			int remain = i / 2;
			hashResult += (asciiChar % m * (int)pow(31, remain) % m * (int)pow(31, i - remain) % m) % m;
		}
		else
		{
			hashResult += (asciiChar % m * (int)pow(31, i) % m) % m;
		}
	}
	return hashResult % m;
}

Company* CreateHashTable(vector<Company> list_company)
{
	Company* list = new Company[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		list[i].name = "";
		list[i].tax_code = "";
		list[i].address = "";
	}
	for (int i = 0; i < list_company.size(); i++)
	{
		int hashValue = HashString(list_company[i].name) % SIZE;
		int j = 0;
		int hashIndex = (hashValue + j) % SIZE;
		while (list[j].name != "")
		{
			++j;
			hashIndex = (hashValue + j) % SIZE;
		}
		list[hashIndex] = list_company[i];
	}

	return list;
}

void Insert(Company* &hash_table, Company company)
{
	for (int i = 0; i < SIZE; i++)
	{
		int hashValue = i % SIZE;
		int j = 0;
		int hashIndex = (hashValue + j) % SIZE;
		while (hash_table[j].name != "")
		{
			++j;
			hashIndex = (hashValue + j) % SIZE;
		}
		hash_table[hashIndex] = company;
		break;
	}
}

Company* Search(Company* hash_table, string company_name)
{
	long long hashValue = HashString(company_name) % SIZE;
	int j = 0;
	long long hashIndex = hashValue + j;
	while(hash_table[hashIndex].name != company_name)
	{
		++j;
		hashIndex = (hashValue + j) % SIZE;
		if (j >= SIZE) return NULL;
	                
	}
	return &hash_table[hashIndex];
}


int main() {

	vector<Company> companyList = readCompanyList("data.txt");
	/*for (int i = 0; i < companyList.size(); i++)
	{
		cout << companyList[i].name << "|" << companyList[i].tax_code << "|" << companyList[i].address << endl;
	}*/
	Company* companies = CreateHashTable(companyList);
	Company company;
	company.name = "hehehehe";
	company.tax_code = "122343";
	company.address = "hohohoho";
	Insert(companies,company);
	for (int i = 0; i < 2000; i++)
	{
		cout << companies[i].name << endl;
	}
	Company* foundCompany = Search(companies, "hehehehe");
	if (foundCompany != NULL) cout << "FOUND: " << foundCompany->name << " | " << foundCompany->tax_code << " | " << foundCompany->address << endl;
	else cout << "NOT FOUND!";
	
	return 0;
}