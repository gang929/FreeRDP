/**
 * WinPR: Windows Portable Runtime
 * Runtime ASSERT macros
 *
 * Copyright 2021 Armin Novak <armin.novak@thincast.com>
 * Copyright 2021 Thincast Technologies GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <winpr/assert.h>
#include <winpr/wlog.h>
#include <winpr/debug.h>

void winpr_int_assert(const char* condstr, const char* file, const char* fkt, size_t line)
{
	wLog* _log_cached_ptr = WLog_Get("com.freerdp.winpr.assert");
	WLog_Print(_log_cached_ptr, WLOG_FATAL, "%s [%s:%s:%" PRIuz "]", condstr, file, fkt, line);
	winpr_log_backtrace_ex(_log_cached_ptr, WLOG_FATAL, 20);
	abort();
}
