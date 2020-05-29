// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "debugtrophies.hpp"
#include <Utils/Kdlsym.hpp>
#include <Utils/Logger.hpp>

using namespace Mira::Plugins;

debugtrophies::debugtrophies()
{

}

debugtrophies::~debugtrophies()
{

}

bool debugtrophies::OnLoad()
{
	auto dtrophyGetInt = (uint32_t(*)(uint32_t p_Id, int32_t* p_OutValue))kdlsym(dtrophyGetInt);

	int32_t rtv;
	
	auto s_Ret = dtrophyGetInt(0x31C0, &rtv);

	if (s_Ret != 0)
	{
		WriteLog(LL_Error, "could not get enable debug trophies activation status");
		return false;
	} else if (rtv == 0) {
		WriteLog(LL_Info, "debug trophies already activated");
		return true;
	}
		WriteLog(LL_Warn, "activating debug trophies");
	
	  s_Ret = dtrophyGetInt(0x31C0, 0);
    if (s_Ret < 0)
      {
        WriteLog(LL_Error, "ssc_enable_debug_trophies");
        return false;
    }
      
    WriteLog(LL_Info, "activated debugtrophies patched");

    return true;
}
bool debugtrophies::OnUnload()
{
		return true;
}

bool debugtrophies::OnSuspend()
{
		return true;
}

bool debugtrophies::OnResume()
{
		return true;
}