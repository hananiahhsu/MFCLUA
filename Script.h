#pragma once
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include <string>
#include <CString>
using namespace std;

class CScript
{
public:
	CScript();
	virtual ~CScript();
public:
	void TCHAR2Char(const TCHAR* tchar, char* _char);
	string GetInstanceFolderPath(void);
	void GetLuaPath(string& lua_path);
public:
	void InitVM(string lua_file_name);
	void TransCostCal(string f,int quantity,double pcs_weight,double unit_price,double& cost);
	void PackCostCal(string str_pack, int quantity, double unit_price, double& cost);
	void AssemCostCal(string str_assem, int quantity, double pcs_weight, double unit_price, double& cost);
	void CloseLua();
	void SetPath(const string str_path);
public:
	lua_State *m_lua_vm;
	string m_lua_path;
};