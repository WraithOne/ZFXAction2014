////////////////////////////////////////////
///
/// WraithOne
/// www.Dark-Abyss.net
///
/// ZFX Action 2014
///
/// Theme: Career, Cell
///
////////////////////////////////////////////

#include <Capp.h>

bool Capp::InitGuard()
{
	// Load Guard Image
	m_Guard = LoadImage(m_Renderer, "Data/GFX/Guard.png");
	if (m_Guard == nullptr)
	{
		Shutdown();

		return false;
	}

	return true;
}

void Capp::UpdateGuard(unsigned int elapsedTime)
{

}

void Capp::RenderGuard(unsigned int elapsedTime)
{

}