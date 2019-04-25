
docker run -i -t -v "E:\works\git\github.com\m2wasabi\techbook5-VRM:/book" ―w /book vvakame/review:2.4 /bin/bash

kanji-config-updmap status 
mktexlsr
review-pdfmaker config.yml 

docker run -t --rm -v "E:\works\git\github.com\m2wasabi\techbook5-VRM:/book" vvakame/review:2.4 /bin/bash -ci "cd /book && ./setup.sh && npm run pdf"
