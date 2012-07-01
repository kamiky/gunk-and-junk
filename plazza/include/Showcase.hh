//
// Showcase.hh for plazza in /home/hugues_v//epitech/cpp/plazza/plazza-2014-hugues_v/trunk
// 
// Made by vincent hugues
// Login   <hugues_v@epitech.net>
// 
// Started on  Wed Apr 13 14:00:51 2011 vincent hugues
// Last update Fri Apr 15 12:11:43 2011 sebastien gatty
//

#ifndef		SHOWCASE_HH_
# define	SHOWCASE_HH_

# include	<string>
# include	<SFML/Graphics.hpp>
# include	<SFML/Audio.hpp>
# include	"Menu.hh"
# include	"common.hh"

class Showcase
{
public:
  Showcase();
  ~Showcase();

  void	 init();
  events keyHndlr(std::string & str);
  void	 display(reports const rep, reports const oldrep);

private:
  Menu			_menu;
  sf::RenderWindow	_win;
  sf::Event		_event;
  sf::String		_text, _ready;
  sf::Image		_imgmenu;
  sf::Sprite		_spritemenu;
  sf::Font		_font;
  //  sf::Music		_music;
  std::string		_note;
};

#endif		/* !SHOWCASE_HH_ */
