#pragma once

namespace StatePattern
{
	class State
	{
	public:
		void OnEnter();
		void OnExit();
		void OnUpdate();
	};
}