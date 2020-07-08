#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class ExtHddSuportEnabler : public Mira::Utils::IModule
				{
				public:
						ExtHddSuportEnabler();
						virtual ~ExtHddSuportEnabler();

						virtual const char* GetName() override { return "ExtHddSuportEnabler"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}
