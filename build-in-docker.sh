#!/bin/bash

# コマンド手打ちで作業したい時は以下の通り /book に pwd がマウントされます
# docker run -i -t -v $(pwd):/book vvakame/review /bin/bash

docker run -i -t -v (""+$Pwd.Path+":/book") vvakame/review /bin/bash

kanji-config-updmap status 
mktexlsr
review-pdfmaker config.yml 

docker run -t --rm -v $(pwd):/book vvakame/review:2.4 /bin/bash -ci "cd /book && ./setup.sh && npm run pdf"
