/**
 * Gaea
 * Copyright (C) 2016 David Jolly
 * ----------------------
 *
 * Gaea is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Gaea is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GAEA_OBJECT_TYPE_H_
#define GAEA_OBJECT_TYPE_H_

namespace gaea {

	namespace engine {

		namespace object {

			#define GAEA_OBJECT_HEADER "[GAEA::ENGINE::OBJECT]"
#ifndef NDEBUG
			#define GAEA_OBJECT_EXCEPTION_HEADER GAEA_OBJECT_HEADER " "
#else
			#define GAEA_OBJECT_EXCEPTION_HEADER
#endif // NDEBUG

			enum {
				GAEA_OBJECT_EXCEPTION_INVALID = 0,
			};

			#define GAEA_OBJECT_EXCEPTION_MAX GAEA_OBJECT_EXCEPTION_INVALID

			static const std::string GAEA_OBJECT_EXCEPTION_STR[] = {
				GAEA_OBJECT_EXCEPTION_HEADER "Invalid object type",
				};

			#define GAEA_OBJECT_EXCEPTION_STRING(_TYPE_) \
				((_TYPE_) > GAEA_OBJECT_EXCEPTION_MAX ? GAEA_OBJECT_EXCEPTION_HEADER EXCEPTION_UNKNOWN : \
				STRING_CHECK(GAEA_OBJECT_EXCEPTION_STR[_TYPE_]))

			#define THROW_GAEA_OBJECT_EXCEPTION(_EXCEPT_) \
				THROW_EXCEPTION(GAEA_OBJECT_EXCEPTION_STRING(_EXCEPT_))
			#define THROW_GAEA_OBJECT_EXCEPTION_FORMAT(_EXCEPT_, _FORMAT_, ...) \
				THROW_EXCEPTION_FORMAT(GAEA_OBJECT_EXCEPTION_STRING(_EXCEPT_), _FORMAT_, __VA_ARGS__)
		}
	}
}

#endif // GAEA_OBJECT_TYPE_H_
