#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class FullDbSettingEnabler : public Mira::Utils::IModule
				{
				public:
						FullDbSettingEnabler();
						virtual ~FullDbSettingEnabler();

						virtual const char* GetName() override { return "FullDbSettingEnabler"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}
