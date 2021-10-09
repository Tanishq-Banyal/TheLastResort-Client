/////////////////////////////////////////////////////////////////////////////////
//
// CNGui 1.1 - Chats Noirs Graphical User Interface
// Copyright (c) 2019 Fatih (accfldekur@gmail.com)
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef PROGRESSINDICATOR_HPP
#define PROGRESSINDICATOR_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
//CNGui
#include <CNGui/Objects/Object.hpp>
#include <CNGui/Tools/Shape.hpp>
#include <CNGui/Tools/Text.hpp>
#include <CNGui/Tools/Easing.hpp>

namespace CNGui
{
////////////////////////////////////////////////////////////
/// \brief Class that creates a graphical progress indicator
///
////////////////////////////////////////////////////////////
class ProgressIndicator : public Object
{
public:
    ////////////////////////////////////////////////////////////
    using           Object::Object;

    ////////////////////////////////////////////////////////////
    /// \brief Add progression to the indicator
    ///
    /// \param progression New progression to add (between 0 and 1)
    ///
    /// \see setProgression
    ///
    ////////////////////////////////////////////////////////////
    void            add(float progression);

    ////////////////////////////////////////////////////////////
    /// \brief Set the progression of the indicator
    ///
    /// \param progression New progression between 0 and 1
    ///
    /// \see getProgression
    ///
    ////////////////////////////////////////////////////////////
    void            setProgression(float progression);

    ////////////////////////////////////////////////////////////
    /// \brief Get the progression of the indicator
    ///
    /// \return Progression between 0 and 1
    ///
    /// \see setProgression
    ///
    ////////////////////////////////////////////////////////////
    float           getProgression();

private:
    ////////////////////////////////////////////////////////////
    /// \brief Stylize the object
    ///
    ////////////////////////////////////////////////////////////
    virtual void    stylize();

    ////////////////////////////////////////////////////////////
    /// \brief Manage the object
    ///
    ////////////////////////////////////////////////////////////
    virtual void    manage();

    ////////////////////////////////////////////////////////////
    /// \brief Draw the object to a render target
    ///
    /// \param target Render target to draw to
    /// \param states Current render states
    ///
    ////////////////////////////////////////////////////////////
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    Shape           mBackground;                ///< Background shape of the indicator
    Shape           mShape;                     ///< Shape of the indicator
    Text            mLabel;                     ///< Description text of the indicator
    Text            mProgression;               ///< Progression text of the indicator
    float           mOldProgression = 0;        ///< Old progression of the indicator
    float           mActualProgression = 0;     ///< Actual progression of the indicator
    float           mNewProgression = 0;        ///< New progression of the indicator to transit to
    sf::Clock       mClock;                     ///< Animation clock
};

} // namespace CNGui

#endif // PROGRESSINDICATOR_HPP
