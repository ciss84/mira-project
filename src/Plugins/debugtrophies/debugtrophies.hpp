#pragma once
#include <Utils/IModule.hpp>
#include <Utils/Types.hpp>

namespace Mira
{
		namespace Plugins
		{
				class  debugtrophies : public Mira::Utils::IModule
				{
				public:
						debugtrophies();
						virtual ~debugtrophies();

						virtual const char* GetName() override { return " debugtrophies"; }
						virtual bool OnLoad() override;
						virtual bool OnUnload() override;
						virtual bool OnSuspend() override;
						virtual bool OnResume() override;
				};
		}
}
