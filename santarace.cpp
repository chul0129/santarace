#include <bangtal.h>
using namespace bangtal;
int main()
{
	auto scene = Scene::create("산타레이스", "images/background.png");
	auto santax = 0;
	auto santa = Object::create("images/santa.png", scene, santax, 500);

	auto playButton= Object::create("images/play.png", scene, 610,30,false);
	auto startButton = Object::create("images/start.png", scene, 590, 70);
	auto endButton = Object::create("images/end.png", scene, 590, 20);

	auto timer = Timer::create(10.f);
	showTimer(timer);
	timer->setOnTimerCallback([&](TimerPtr)->bool {
		showMessage("헉...선물배달 실패");
		playButton->hide();
		startButton->setImage("images/restart.png");
		startButton->show();
		endButton->show();

		return true;
		});

	playButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		//산타를 30 만큼 이동시킨다
		santax += 30;
		santa->locate(scene, santax, 500);
		if (santax > 1280)
		{
			showMessage("선물 배달 성공~~~");
			timer->stop();
			playButton->hide();
			startButton->setImage("images/restart.png");
			startButton->show();
			endButton->show();
		}
		return true;
		});
	

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		endButton->hide();
		playButton->show();
		santax = 0;
		santa->locate(scene, santax, 500);
		timer->set(10.f);
		timer->start();
	



		return true;
		});
	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		endGame();
		return true;
		});




	startGame(scene);
	return 0;
}
