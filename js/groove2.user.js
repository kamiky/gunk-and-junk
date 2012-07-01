// ==UserScript==
// @include http://listen.grooveshark.com/*
// @include http://www.grooveshark.com
// @include http://grooveshark.com/*
// ==/UserScript==

/*
** Removes the sidebar
** Updated on 01/07/2012
**/

window.addEventListener('load' ,function () {
	
	var tmp = document.getElementsByClassName("page_column page_column_fixed page_column_capital");
	if (tmp.length == 0)
		return;
	var ads = tmp[0];
	var w = parseInt(ads.style.width);
	
	ads.parentNode.removeChild(ads);
	
	var song_list = document.getElementsByClassName("page_column page_column_fluid last")[0];
	song_list.style.width = parseInt(song_list.style.width) + w + "px";
	
	
	
	
}, false);


//page_column page_column_fixed page_column_capital
//page_column page_column_fluid last