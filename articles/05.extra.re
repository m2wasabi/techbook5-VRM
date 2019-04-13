= VRMの逆引きQ&A

== VRMのマテリアル MToon を使いこなしたい

MToon作者、さんたーPさんの資料を読むと良いでしょう。

資料：@<href>{https://niconare.nicovideo.jp/watch/kn3485}

他にも続刊の『VRM FANBOOK2@<fn>{vrmfanbook2}』に特集しています。よかったらご覧ください。
//footnote[vrmfanbook2][@<href>{https://m2wasabi.booth.pm/items/1270343}]

== ランタイムロードしたときに光り方がおかしい

UniVRM 0.43 現在、ノーマルマップに不具合を抱えています。
今これがホットに修正中のようなので、独自にあれこれ手を尽くすと、徒労に終わりそうです。
次期バージョンを待ちましょう。

== スカートが貫通する

VRM Spring Boneは角度制限や軸固定などの剛体の挙動を抑制する機能が無いので、
スカートのボーンがバラけて足の上を流れ落ちてしまいます。@<fn>{5.skirt}
//footnote[5.skirt][@<href>{https://twitter.com/m2wasabi/status/1007273436077387777}]

楽したい人は VRM Spring Boneの更新を待ちましょう。

VRMに仕様拡張の提案が許されるのならば、UnityちゃんSpringBone2を導入する拡張@<fn>{springyami}を書きたいですね。
//footnote[springyami][UnityちゃんSpringBone2を導入を導入しようとして仕様の闇を見ました。DynamicBoneなら許せる。詳しくは続刊の『VRM FANBOOK2』をご確認ください。]

== 揺れものがペチャンコになる

VRM SpringBoneのコライダーは、親ボーンと自分の延長線上に生えます。
コライダーが上向きに生えてないか確認してみましょう。
詳しくは続刊の『VRM FANBOOK2@<fn>{vrmfanbook2}』をご確認ください。
もちろん上向きのコライダーは、Gravity 1.0 にすると下を向きます。
なおバーチャルキャスト内では Gravity = 0 のようです。@<fn>{5.gravity}

//footnote[5.gravity][@<href>{https://twitter.com/YakiuchiHo_ka/status/1047486572331814913}]

== UVアニメーションできない

できます！！！
BlendShapePloxy のマテリアルモーフを活用しましょう。
詳しくは続刊の『VRM FANBOOK2@<fn>{vrmfanbook2}』をご覧ください。

== DRM・暗号化が欲しい

アバター共有プラットフォームで対応できているサービスを使いましょう。
VRoidHub@<fn>{vroidhub}はモデル利用APIの暗号化に対応しています。
ザ・シードオンライン@<fn>{TSO}はVRMに指紋情報を追加してアプリ追跡ができるようです。

//footnote[vroidhub][@<href>{https://hub.vroid.com/,VRoidHub}]
//footnote[TSO][@<href>{https://seed.online/,THE SEED ONLINE}]

== Blend Shape Ploxy で表情拡張したけど誰も使ってくれない

現状、Blend Shape Ploxyで独自の表情を追加しても、アプリケーション側で対応するものがないため、あまり使われません。

標準の表情で工夫するのがベターです。

== 〇〇がないのですが

追加の機能が欲しかったらIssue投げましょう。仕様として採用されるか分かりませんが。

それか文句言う前に実装してPullRequestしましょう。仕様として採用されるか分かりませんが。

== UnrealEngine…

VRM4U@<fn>{VRM4U}を応援しましょう！！！
//footnote[VRM4U][@<href>{https://github.com/ruyo/VRM4U}]

== ニコニ立体ちゃんをglbファイルにすると読み込めない

ニコニ立体で公開されているVRMニコニ立体ちゃんは、エクスポートされたVRMが古いので、
glTFファイルとして正しくありません。

正しいglTFファイルにするには、一度最新のUniVRMに取り込んで、再エクスポートしましょう。
あとHumanoidボーン設定で、必須ボーンではないChestが未定義です。追加しないとVRoidHubにアップできませんので注意しましょう。
