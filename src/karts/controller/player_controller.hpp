//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2004-2005 Steve Baker <sjbaker1@airmail.net>
//  Copyright (C) 2006 Joerg Henrichs, Steve Baker
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.


#ifndef HEADER_PLAYERKART_HPP
#define HEADER_PLAYERKART_HPP

#include "config/player.hpp"
#include "karts/controller/controller.hpp"

class SFXBase;
class Player;

/** PlayerKart manages control events from the player and moves
    them to the Kart */
class PlayerController : public Controller
{
private:
    int            m_steer_val, m_steer_val_l, m_steer_val_r;
    int            m_prev_accel;
    bool           m_prev_brake;

    float          m_penalty_time;

    SFXBase       *m_bzzt_sound;
    SFXBase       *m_wee_sound;
    SFXBase       *m_ugh_sound;
    SFXBase       *m_grab_sound;
    SFXBase       *m_full_sound;

    void           steer(float, int);
public:
                   PlayerController  (Kart *kart, StateManager::ActivePlayer *_player,
                                      unsigned int player_index);
                  ~PlayerController  ();
    void           update            (float);
    void           action            (PlayerAction action, int value);
    void           handleZipper      ();
    void           collectedItem     (const Item &item, int add_info=-1,
                                      float previous_energy=0);
    virtual void   setPosition       (int p);
    virtual void   finishedRace      (float time);
    bool           isPlayerController() const {return true;}
    virtual void   reset             ();
    void           resetInputState   ();
};

#endif
