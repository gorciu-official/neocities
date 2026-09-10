#pragma once

#define EL_CENTER(...) \
    CR_ELEMENT( \
        "div", CR_ATTRS( \
            CR_ATTR("class", "center") \
        ), \
        __VA_ARGS__ \
    )

#define EL_LINK_OUT(target_url, ...) \
    CR_ELEMENT ( \
        "a", CR_ATTRS( \
            CR_ATTR("href", target_url), \
            CR_ATTR("target", "_blank") \
        ), __VA_ARGS__ \
    )

#define EL_PARAGRAPH(...) \
    CR_ELEMENT( \
        "p", CR_ATTRS(), \
        __VA_ARGS__ \
    )
