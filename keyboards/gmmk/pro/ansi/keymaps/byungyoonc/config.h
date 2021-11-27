/* Copyright 2021 Choi, Byungyoon <byungyoonc@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#if defined(DEBOUNCE)
#    undef DEBOUNCE
#endif  // DEBOUNCE
/* High debounce time is required to avoid key chattering because of the debouncing algorithm sym_eager_pk */
#define DEBOUNCE 40

#if !defined(FORCE_NKRO)
#    define FORCE_NKRO
#endif  // FORCE_NKRO
