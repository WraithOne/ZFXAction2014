////////////////////////////////////////////
///
/// WraithOne
/// www.Dark-Abyss.net
///
/// ZFX Action 2014
///
/// Theme:
///
////////////////////////////////////////////
#include <platform.h>
#include <Capp.h>

int main(int argc, char *argv[])
{
	Capp app;

	if (!app.Init())
		return -1;

	app.Run();

	return 0;
}