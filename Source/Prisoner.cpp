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

bool Capp::InitPrisoner()
{
	// Load Prisoner Image
	m_Prisoner = LoadImage(m_Renderer, "Data/GFX/Prisoner.png");
	if (m_Prisoner == nullptr)
	{
		Shutdown();

		return false;
	}

	return true;
}

void Capp::UpdatePrisoner(unsigned int elapsedTime)
{

}

void Capp::RenderPrisoner(unsigned int elapsedTime)
{

}