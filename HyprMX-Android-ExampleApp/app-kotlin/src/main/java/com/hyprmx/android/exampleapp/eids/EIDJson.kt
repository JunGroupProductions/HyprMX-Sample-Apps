@file:JvmName("EIDJson")

package com.hyprmx.android.exampleapp.eids

object EIDJson {
  @JvmField val EXTRA_USER_EIDS_KEY = "eids"

  @JvmField val UID2 =
    """
    {
        "uid2": [{
            "id": "testUID2Id"
        }]
    }
    """

  @JvmField val ID5 =
    """
    {
        "id5": [{
            "id": "testID5id",
            "linkType": 1,
            "abTestingControlGroup": true
        }]
    }
    """

  @JvmField val LIVE_INTENT =
    """
    {
        "liveintent": [{
            "id": "testLiveintentId",
            "atype": 1
        }]
    }
    """

  @JvmField val MULTIPLE_EIDS =
    """
    {
        "uid2": [
            {
                "id": "testUID2Id"
            }
        ],
        "id5": [
            {
                "id": "testID5Id",
                "linkType": 2,
                "abTestingControlGroup": true
            }
        ],
        "liveintent": [
            {
                "id": "testLiveintentId",
                "atype": 1
            }
        ]
    }
    """
}
