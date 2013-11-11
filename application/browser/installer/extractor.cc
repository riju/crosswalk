// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/application/browser/installer/extractor.h"

#include "base/file_util.h"
#include "base/logging.h"
#include "base/path_service.h"
#include "third_party/zlib/google/zip.h"

namespace xwalk {
namespace application {

Extractor::Extractor() {
}

Extractor::~Extractor() {
}

// static
scoped_refptr<Extractor> Extractor::Create(
    const base::FilePath& source_path) {
  if (base::PathExists(source_path))
      return scoped_refptr<Extractor>(new Extractor(source_path));
  else
    return NULL;
}

Extractor::Extractor(const base::FilePath& source_path)
    : source_path_(source_path),
      package_(Package::Create(source_path)) {
}

std::string Extractor::GetPackageID() const {
  return package_.get()?package_->Id():"";
}

bool Extractor::Extract(base::FilePath* target_path) {
  if (!package_.get() ||
      !package_->IsOk()) {
    LOG(ERROR) << "XPK/WGT file is broken.";
    return false;
  }

  if (!CreateTempDirectory()) {
    LOG(ERROR) << "Can't create a temporary"
                  "directory for extracting the package content.";
    return false;
  }

  if (!zip::Unzip(source_path_, temp_dir_.path())) {
    LOG(ERROR) << "An error occurred during package extraction";
    return false;
  }

  *target_path = temp_dir_.path();
  return true;
}

// Create a temporary directory to decompress the XPK/WGT package.
// As the package information might already exists under data_path,
// it's safer to extract the XPK file into a temporary directory first.
bool Extractor::CreateTempDirectory() {
  base::FilePath tmp;
  PathService::Get(base::DIR_TEMP, &tmp);
  if (tmp.empty())
    return false;
  if (!temp_dir_.CreateUniqueTempDirUnderPath(tmp))
    return false;
  return true;
}

}  // namespace application
}  // namespace xwalk
