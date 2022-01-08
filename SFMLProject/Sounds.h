#pragma once
#include <iostream>
#include <unordered_map>
#include <SFML/Audio.hpp>
class Sounds
{

public:

	static void RegisterSound(const char * name, const char* filePath);
	static void PlayerRegisteredSound(const char* name);

private:

	static std::unordered_map <const char*,  sf::SoundBuffer> soundBuffers;
	static sf::Sound sound;
};

