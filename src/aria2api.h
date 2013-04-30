/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2013 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef ARIA2_API_H
#define ARIA2_API_H

#include "common.h"

#include <aria2/aria2.h>
#include "SharedHandle.h"

namespace aria2 {

struct Context;

struct Session {
  Session(const KeyVals& options);
  ~Session();
  SharedHandle<Context> context;
};

struct DownloadHandle {
  virtual ~DownloadHandle() {}
  virtual DOWNLOAD_STATUS getStatus() = 0;
  virtual int64_t getTotalLength() = 0;
  virtual int64_t getCompletedLength() = 0;
  virtual int64_t getUploadLength() = 0;
  virtual std::string getBitfield() = 0;
  virtual int getDownloadSpeed() = 0;
  virtual int getUploadSpeed() = 0;
  virtual size_t getNumPieces() = 0;
  virtual int getConnections() = 0;
  virtual int getErrorCode() = 0;
  virtual const std::vector<A2Gid>& getFollowedBy() = 0;
  virtual A2Gid getBelongsTo() = 0;
  virtual const std::string& getDir() = 0;
};

} // namespace aria2

#endif // ARIA2_API_H
