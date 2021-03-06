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

#ifndef GAEA_CAMERA_TYPE_H_
#define GAEA_CAMERA_TYPE_H_

namespace gaea {

	namespace engine {

		namespace camera {

			#define GAEA_CAMERA_HEADER "[GAEA::ENGINE::CAMERA]"
#ifndef NDEBUG
			#define GAEA_CAMERA_EXCEPTION_HEADER GAEA_CAMERA_HEADER " "
#else
			#define GAEA_CAMERA_EXCEPTION_HEADER
#endif // NDEBUG

			enum {
				GAEA_CAMERA_EXCEPTION_ALLOCATED = 0,
				GAEA_CAMERA_EXCEPTION_ENTRY_ALLOCATED,
				GAEA_CAMERA_EXCEPTION_INITIALIZED,
				GAEA_CAMERA_EXCEPTION_INVALID_CONTEXT,
				GAEA_CAMERA_EXCEPTION_INVALID_EVENT,
				GAEA_CAMERA_EXCEPTION_UNINITALIZED,
			};

			#define GAEA_CAMERA_EXCEPTION_MAX GAEA_CAMERA_EXCEPTION_UNINITALIZED

			static const std::string GAEA_CAMERA_EXCEPTION_STR[] = {
				GAEA_CAMERA_EXCEPTION_HEADER "Failed to allocate camera manager",
				GAEA_CAMERA_EXCEPTION_HEADER "Failed to allocate camera entry",
				GAEA_CAMERA_EXCEPTION_HEADER "Camera manager is initialized",
				GAEA_CAMERA_EXCEPTION_HEADER "Invalid context",
				GAEA_CAMERA_EXCEPTION_HEADER "Invalid event context",
				GAEA_CAMERA_EXCEPTION_HEADER "Camera manager is uninitialized",
				};

			#define GAEA_CAMERA_EXCEPTION_STRING(_TYPE_) \
				((_TYPE_) > GAEA_CAMERA_EXCEPTION_MAX ? GAEA_CAMERA_EXCEPTION_HEADER EXCEPTION_UNKNOWN : \
				STRING_CHECK(GAEA_CAMERA_EXCEPTION_STR[_TYPE_]))

			#define THROW_GAEA_CAMERA_EXCEPTION(_EXCEPT_) \
				THROW_EXCEPTION(GAEA_CAMERA_EXCEPTION_STRING(_EXCEPT_))
			#define THROW_GAEA_CAMERA_EXCEPTION_FORMAT(_EXCEPT_, _FORMAT_, ...) \
				THROW_EXCEPTION_FORMAT(GAEA_CAMERA_EXCEPTION_STRING(_EXCEPT_), _FORMAT_, __VA_ARGS__)
		}
	}
}

#endif // GAEA_CAMERA_TYPE_H_
