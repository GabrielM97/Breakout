#include "Sounds.h"

std::unordered_map <const char*, sf::SoundBuffer> Sounds::soundBuffers;
sf::Sound Sounds::sound;

void Sounds::RegisterSound(const char* name, const char* filePath)
{
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile(filePath))
	{
		soundBuffers.insert(std::make_pair(name, buffer));
	}
}

void Sounds::PlayerRegisteredSound(const char* name)
{
	sound.setBuffer(soundBuffers[name]);
	sound.play();
}
