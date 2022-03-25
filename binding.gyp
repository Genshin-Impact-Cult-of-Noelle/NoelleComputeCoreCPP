    {
      "targets": [
        {
            "include_dirs":[
                "<!(node -e \"require('nan')\")"
            ],
          "target_name": "NoelleCore",
          "sources": [ "src/main.cpp","src/Core/Base.cpp" ]
        }
      ]
    }