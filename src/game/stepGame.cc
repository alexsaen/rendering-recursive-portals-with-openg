#include "game.ih"

void Game::stepGame()
{
	if (not d_running)
		return;

	float deltaTime = d_win.GetFrameTime();

	d_player.update(deltaTime);

	// Update all objects (drawable entities)
	for (Object *object : d_objects)
		object->update(deltaTime);


	ostringstream oss;
	oss << "FPS: " << d_fps << "\n\n"
		<< "X: " << d_player.position().x << '\n'
		<< "Y: " << d_player.position().y << '\n'
		<< "Z: " << d_player.position().z << '\n';
	d_debugText->setText(oss.str());
}
