// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_APPLICATION_BROWSER_INSTALLER_PACKAGE_H_
#define XWALK_APPLICATION_BROWSER_INSTALLER_PACKAGE_H_

#include <string>
#include <vector>

#include "base/files/file_path.h"
#include "base/memory/scoped_handle.h"
#include "base/memory/scoped_ptr.h"

namespace xwalk {
namespace application {

class Package {
 public:
  Package();
  Package(ScopedStdioHandle* file, bool is_ok);
  virtual ~Package();
  // Validate the xpk/wgt file
  bool IsOk() const { return is_ok_; }
  const std::string& Id() const { return id_; }
  static scoped_ptr<Package> Create(const base::FilePath& path);
 protected:
  enum PACKAGE_TYPE {
      XPK,
      WGT
    };
  scoped_ptr<ScopedStdioHandle> file_;
  bool is_ok_;
  std::string id_;
};

}  // namespace application
}  // namespace xwalk

#endif  // XWALK_APPLICATION_BROWSER_INSTALLER_PACKAGE_H_
