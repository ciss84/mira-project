#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class SaveDataMountEnabler : public Mira::Utils::IModule
				{
				public:
						SaveDataMountEnabler();
						virtual ~SaveDataMountEnabler();

						virtual const char* GetName() override { return "SaveDataMountEnabler"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}