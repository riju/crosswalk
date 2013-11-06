// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef APPLICATION_BROWSER_INSTALLER_WGT_PACKAGE_H_
#define APPLICATION_BROWSER_INSTALLER_WGT_PACKAGE_H_

#include <string>
#include <vector>

#include "base/files/file_path.h"
#include "base/memory/scoped_handle.h"
#include "base/memory/scoped_ptr.h"
#include "xwalk/application/browser/installer/package.h"

namespace xwalk {
namespace application {

class WGTPackage : public Package {
 public:
  WGTPackage();
  ~WGTPackage();
  static scoped_ptr<Package> Create(const base::FilePath& path);  // OVERRIDE;

 private:
  explicit WGTPackage(ScopedStdioHandle* file);
};

}  // namespace application
}  // namespace xwalk

#endif  // APPLICATION_BROWSER_INSTALLER_WGT_PACKAGE_H_
