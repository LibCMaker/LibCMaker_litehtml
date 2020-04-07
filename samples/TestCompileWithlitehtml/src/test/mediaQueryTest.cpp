#include <assert.h>
#include "litehtml/litehtml.h"
#include "containers/test/container_test.h"
using namespace litehtml;

static void MediaQueryCheckTest() {
  media_query_expression e;
  media_features k;

  e = media_query_expression(), e.feature = media_feature_width, e.val = 100;
  k = media_features(), k.width = 0, assert(!e.check(k));
  k = media_features(), k.width = 100, assert(e.check(k));
  k = media_features(), k.width = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_width, e.val = 100;
  k = media_features(), k.width = 0, assert(!e.check(k));
  k = media_features(), k.width = 100, assert(e.check(k));
  k = media_features(), k.width = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_width, e.val = 100;
  k = media_features(), k.width = 0, assert(e.check(k));
  k = media_features(), k.width = 100, assert(e.check(k));
  k = media_features(), k.width = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_height, e.val = 100;
  k = media_features(), k.height = 0, assert(!e.check(k));
  k = media_features(), k.height = 100, assert(e.check(k));
  k = media_features(), k.height = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_height, e.val = 100;
  k = media_features(), k.height = 0, assert(!e.check(k));
  k = media_features(), k.height = 100, assert(e.check(k));
  k = media_features(), k.height = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_height, e.val = 100;
  k = media_features(), k.height = 0, assert(e.check(k));
  k = media_features(), k.height = 100, assert(e.check(k));
  k = media_features(), k.height = 500, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_device_width, e.val = 100;
  k = media_features(), k.device_width = 0, assert(!e.check(k));
  k = media_features(), k.device_width = 100, assert(e.check(k));
  k = media_features(), k.device_width = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_device_width, e.val = 100;
  k = media_features(), k.device_width = 0, assert(!e.check(k));
  k = media_features(), k.device_width = 100, assert(e.check(k));
  k = media_features(), k.device_width = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_device_width, e.val = 100;
  k = media_features(), k.device_width = 0, assert(e.check(k));
  k = media_features(), k.device_width = 100, assert(e.check(k));
  k = media_features(), k.device_width = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_device_height, e.val = 100;
  k = media_features(), k.device_height = 0, assert(!e.check(k));
  k = media_features(), k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_height = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_device_height, e.val = 100;
  k = media_features(), k.device_height = 0, assert(!e.check(k));
  k = media_features(), k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_height = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_device_height, e.val = 100;
  k = media_features(), k.device_height = 0, assert(e.check(k));
  k = media_features(), k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_height = 500, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_orientation, e.val = (int)media_orientation_portrait;
  k = media_features(), k.width = 0, k.height = 100, assert(e.check(k));
  k = media_features(), k.width = 100, k.height = 100, assert(e.check(k));
  k = media_features(), k.width = 500, k.height = 100, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_orientation, e.val = (int)media_orientation_landscape;
  k = media_features(), k.width = 0, k.height = 100, assert(!e.check(k));
  k = media_features(), k.width = 100, k.height = 100, assert(!e.check(k));
  k = media_features(), k.width = 500, k.height = 100, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_aspect_ratio, e.val = 100, e.val2 = 100;
  k = media_features(), k.width = 0, k.height = 100, assert(!e.check(k));
  k = media_features(), k.width = 100, k.height = 100, assert(e.check(k));
  k = media_features(), k.width = 500, k.height = 100, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_aspect_ratio, e.val = 100, e.val2 = 100;
  k = media_features(), k.width = 0, k.height = 100, assert(!e.check(k));
  k = media_features(), k.width = 100, k.height = 100, assert(e.check(k));
  k = media_features(), k.width = 500, k.height = 100, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_aspect_ratio, e.val = 100, e.val2 = 100;
  k = media_features(), k.width = 0, k.height = 100, assert(e.check(k));
  k = media_features(), k.width = 100, k.height = 100, assert(e.check(k));
  k = media_features(), k.width = 500, k.height = 100, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_device_aspect_ratio, e.val = 100, e.val2 = 100;
  k = media_features(), k.device_width = 0, k.device_height = 100, assert(!e.check(k));
  k = media_features(), k.device_width = 100, k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_width = 500, k.device_height = 100, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_device_aspect_ratio, e.val = 100, e.val2 = 100;
  k = media_features(), k.device_width = 0, k.device_height = 100, assert(!e.check(k));
  k = media_features(), k.device_width = 100, k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_width = 500, k.device_height = 100, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_device_aspect_ratio, e.val = 100, e.val2 = 100;
  k = media_features(), k.device_width = 0, k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_width = 100, k.device_height = 100, assert(e.check(k));
  k = media_features(), k.device_width = 500, k.device_height = 100, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_color, e.val = 100;
  k = media_features(), k.color = 0, assert(!e.check(k));
  k = media_features(), k.color = 100, assert(e.check(k));
  k = media_features(), k.color = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_color, e.val = 100;
  k = media_features(), k.color = 0, assert(!e.check(k));
  k = media_features(), k.color = 100, assert(e.check(k));
  k = media_features(), k.color = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_color, e.val = 100;
  k = media_features(), k.color = 0, assert(e.check(k));
  k = media_features(), k.color = 100, assert(e.check(k));
  k = media_features(), k.color = 500, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_color_index, e.val = 100;
  k = media_features(), k.color_index = 0, assert(!e.check(k));
  k = media_features(), k.color_index = 100, assert(e.check(k));
  k = media_features(), k.color_index = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_color_index, e.val = 100;
  k = media_features(), k.color_index = 0, assert(!e.check(k));
  k = media_features(), k.color_index = 100, assert(e.check(k));
  k = media_features(), k.color_index = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_color_index, e.val = 100;
  k = media_features(), k.color_index = 0, assert(e.check(k));
  k = media_features(), k.color_index = 100, assert(e.check(k));
  k = media_features(), k.color_index = 500, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_monochrome, e.val = 100;
  k = media_features(), k.monochrome = 0, assert(!e.check(k));
  k = media_features(), k.monochrome = 100, assert(e.check(k));
  k = media_features(), k.monochrome = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_monochrome, e.val = 100;
  k = media_features(), k.monochrome = 0, assert(!e.check(k));
  k = media_features(), k.monochrome = 100, assert(e.check(k));
  k = media_features(), k.monochrome = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_monochrome, e.val = 100;
  k = media_features(), k.monochrome = 0, assert(e.check(k));
  k = media_features(), k.monochrome = 100, assert(e.check(k));
  k = media_features(), k.monochrome = 500, assert(!e.check(k));

  e = media_query_expression(), e.feature = media_feature_resolution, e.val = 100;
  k = media_features(), k.resolution = 0, assert(!e.check(k));
  k = media_features(), k.resolution = 100, assert(e.check(k));
  k = media_features(), k.resolution = 500, assert(!e.check(k));
  e = media_query_expression(), e.feature = media_feature_min_resolution, e.val = 100;
  k = media_features(), k.resolution = 0, assert(!e.check(k));
  k = media_features(), k.resolution = 100, assert(e.check(k));
  k = media_features(), k.resolution = 500, assert(e.check(k));
  e = media_query_expression(), e.feature = media_feature_max_resolution, e.val = 100;
  k = media_features(), k.resolution = 0, assert(e.check(k));
  k = media_features(), k.resolution = 100, assert(e.check(k));
  k = media_features(), k.resolution = 500, assert(!e.check(k));
}

static void MediaQueryParseTest() {
  container_test container;
  litehtml::document::ptr doc = std::make_shared<litehtml::document>(&container, nullptr);
  media_query::ptr q;
  q = media_query::create_from_string(_t(""), doc);
  q = media_query::create_from_string(_t("not"), doc);
  q = media_query::create_from_string(_t("(width)"), doc);
  q = media_query::create_from_string(_t("(orientation: portrait)"), doc);
  q = media_query::create_from_string(_t("(width: 1 / 2)"), doc);
  q = media_query::create_from_string(_t("(width: 300px)"), doc);
  q = media_query::create_from_string(_t("print"), doc);
  q = media_query::create_from_string(_t("only screen and (max-width: 600px)"), doc);
}

void mediaQueryTest() {
  MediaQueryCheckTest();
  MediaQueryParseTest();
}
