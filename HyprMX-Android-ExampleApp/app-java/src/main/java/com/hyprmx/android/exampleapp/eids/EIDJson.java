package com.hyprmx.android.exampleapp.eids;

public class EIDJson {
  public static final String EXTRA_USER_EIDS_KEY = "eids";

  public static final String UID2 =
    """
    {
        "uid2": [{
            "id": "testUID2Id"
        }]
    }
    """;

  public static final String ID5 =
    """
    {
        "id5": [{
            "id": "testID5id",
            "linkType": 1,
            "abTestingControlGroup": true
        }]
    }
    """;

  public static final String LIVE_INTENT =
    """
    {
        "liveintent": [{
            "id": "testLiveintentId",
            "atype": 1
        }]
    }
    """;

  public static final String MULTIPLE_EIDS =
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
    """;
}
