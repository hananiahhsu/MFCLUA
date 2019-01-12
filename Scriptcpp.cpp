#pragma once
#include "stdafx.h"
#include "Script.h"

CScript::CScript()
{
	m_lua_path = "";
}
CScript::~CScript()
{
	CloseLua();
}



string CScript::GetInstanceFolderPath(void)
{
	string exePath = "";
	TCHAR tcFullPath[MAX_PATH];
	char* pChPath = new char[MAX_PATH];
	memset(pChPath, '\0', MAX_PATH);
	GetModuleFileName(NULL, tcFullPath, MAX_PATH);
	TCHAR2Char(tcFullPath, pChPath);
	exePath = string(pChPath);

	string dirPath = "";
	size_t iPos = exePath.rfind("\\");
	dirPath = exePath.substr(0, iPos);
	delete[] pChPath;
	return dirPath;
}

void CScript::TCHAR2Char(const TCHAR* tchar, char* _char)
{
	int iLength = 0;
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}


void CScript::GetLuaPath(string& lua_path)
{
	string str_path;
	str_path = GetInstanceFolderPath();
	lua_path = str_path;
	lua_path += "\\script\\";
}


void CScript::InitVM(string lua_file_name)
{
	m_lua_vm = luaL_newstate();
	luaopen_base(m_lua_vm);
	luaL_openlibs(m_lua_vm);
	if (NULL == m_lua_vm)
	{
		MessageBox(NULL,L"Failed to init lua!",L"Error",MB_OKCANCEL);
		return;
	}
	lua_pushcfunction(m_lua_vm,);

	string lua_path;
	GetLuaPath(m_lua_path);
	lua_path = m_lua_path;
	lua_path += lua_file_name;
	luaL_dofile(m_lua_vm, lua_path.c_str());
}

void CScript::TransCostCal(string str_trans, int quantity,double pcs_weight,double unit_price,double& cost)
{
	string str_msg;
	lua_getglobal(m_lua_vm, "TransportationCostCal");
	lua_pushstring(m_lua_vm, str_trans.c_str());
	lua_pushinteger(m_lua_vm, quantity);
	lua_pushnumber(m_lua_vm, pcs_weight);
	lua_pushnumber(m_lua_vm, unit_price);
	if (lua_pcall(m_lua_vm, 4, 1, 0) != 0)
	{
		str_msg = lua_tostring(m_lua_vm, -1);
		lua_pop(m_lua_vm, 1);
	}
	if (!lua_isnumber(m_lua_vm,-1))
	{
		str_msg = lua_tostring(m_lua_vm, -1);
		lua_pop(m_lua_vm,1);
	}
	cost = lua_tonumber(m_lua_vm,-1);
}

void CScript::AssemCostCal(string str_assem, int quantity, double pcs_weight, double unit_price, double& cost)
{
	string str_msg;
	lua_getglobal(m_lua_vm, "AssemblyCostCal");
	lua_pushstring(m_lua_vm, str_assem.c_str());
	lua_pushinteger(m_lua_vm, quantity);
	lua_pushnumber(m_lua_vm, pcs_weight);
	lua_pushnumber(m_lua_vm, unit_price);
	if (lua_pcall(m_lua_vm, 4, 1, 0) != 0)
	{
		str_msg = lua_tostring(m_lua_vm, -1);
		lua_pop(m_lua_vm, 1);
	}
	if (!lua_isnumber(m_lua_vm, -1))
	{
		str_msg = lua_tostring(m_lua_vm, -1);
		lua_pop(m_lua_vm, 1);
	}
	cost = lua_tonumber(m_lua_vm, -1);
}

void CScript::PackCostCal(string str_pack, int quantity,double unit_price, double& cost)
{
	string str_msg;
	lua_getglobal(m_lua_vm, "PackingCostCal");
	lua_pushstring(m_lua_vm, str_pack.c_str());
	lua_pushinteger(m_lua_vm, quantity);
	lua_pushnumber(m_lua_vm, unit_price);
	if (lua_pcall(m_lua_vm, 3, 1, 0) != 0)
	{
		str_msg = lua_tostring(m_lua_vm, -1);
		lua_pop(m_lua_vm, 1);
	}
	if (!lua_isnumber(m_lua_vm, -1))
	{
		str_msg = lua_tostring(m_lua_vm, -1);
		lua_pop(m_lua_vm, 1);
	}
	cost = lua_tonumber(m_lua_vm, -1);
}


void CScript::CloseLua()
{
	lua_close(m_lua_vm);
}

void CScript::SetPath(const string str_path)
{
	m_lua_path = str_path;
}


