//
// Showcase.cpp for plazza in /home/hugues_v//epitech/cpp/plazza/plazza-2014-hugues_v/trunk
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Wed Apr 13 14:00:16 2011 vincent hugues
// Last update Fri Apr 15 14:15:30 2011 sebastien gatty
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "Showcase.hh"
#include "Menu.hh"
#include "common.hh"

Showcase::Showcase()
{
}

Showcase::~Showcase()
{
  _win.Close();
}

void	Showcase::init()
{
  _win.Create(sf::VideoMode(1200, 800, 32), "Plazza");
  if (!_imgmenu.LoadFromFile("./media/bg.png"))
    std::cerr << "Unable to load image" << std::endl;
  _spritemenu.SetImage(_imgmenu);
  _spritemenu.SetPosition(0, 0);
  _font.LoadFromFile("./media/MonospaceTypewriter.ttf");
  _text.SetFont(_font);
  _text.SetColor(sf::Color(0, 0, 0));
  _text.SetPosition(300, 248);
  _text.SetSize(25);
  _ready.SetColor(sf::Color(0, 0, 0));
  _ready.SetSize(25);
  /*if (!_music.OpenFromFile("./media/music.ogg"))
  std::cerr << "Unable to load music" << std::endl;
  else
    {
      _music.SetLoop(true);
      _music.Play();
    }*/
}

events	Showcase::keyHndlr(std::string & str)
{
  events ret = NONE;

  while (_win.GetEvent(_event))
    {
      if (_event.Type == sf::Event::TextEntered)
	{
	  if (((_event.Text.Unicode > 30
		&& _event.Text.Unicode < 127)
	       || _event.Text.Unicode > 159))
	    _note += static_cast<char>(_event.Text.Unicode);
	}
      else if (_event.Type == sf::Event::KeyPressed)
	{
	  switch (_event.Key.Code)
	    {
	    case sf::Key::Return :
	      str = _note;
	      _note = "";
	      ret = ORDER;
	      break;
	    case sf::Key::Escape :
	      ret = QUIT;
	      break;
	    case sf::Key::Back :
	      if (_note.length() > 0)
		_note.erase(_note.end() - 1);
	      break;
	    default : break;
	    }
	}
    }
  return (ret);
}

void			Showcase::display(reports const rep, reports const oldrep)
{
  std::stringstream	sstr;
  int			i, j, x, y;
  int			ready[NB_PIZZA];
  constitreports       	it;

  for (i = 0; i < NB_PIZZA; ready[i++] = 0);
  _win.Clear(sf::Color(0, 0, 0));
  if (_note.length() > 32)
    _text.SetText(_note.substr((_note.length() - 32), 32));
  else
    _text.SetText(_note);
  _win.Draw(_spritemenu);
  _win.Draw(_text);
  for (it = rep.begin(), i = 0, x = 15, y = 385; it != rep.end(); ++it, ++i, y += 30)
    {
      for (j = 0; j < NB_PIZZA; ++j)
	ready[j] += (*it).ready[j];
      _ready.SetPosition(x, y);
      _ready.SetText("Cuisine " + utos(i + 1) + " : "
		     + utos((*it).inPrep) + " en preparation et "
		     + utos((*it).waiting) + " en attente.");
      _win.Draw(_ready);
      
    }
  for (it = oldrep.begin(); it != oldrep.end(); ++it)
    for (j = 0; j < NB_PIZZA; ++j)
      ready[j] += (*it).ready[j];
  for (i = 0, x = 305, y = 318; i < NB_PIZZA; ++i)
    {
      _ready.SetPosition(x + i * 125, y);
      _ready.SetText(utos(ready[i]));
      _win.Draw(_ready);
    }
  _win.Display();
}
