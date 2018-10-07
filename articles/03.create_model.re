= VRMモデルのセットアップ

この章ではFBXモデルからVRMモデルのコンバート・調整の手順を解説していきます。
内容的には弊ブログの記事@<fn>{3.link.blogkiji}に、SpringBoneやモデルの調整を追加したものになります。

//footnote[3.link.blogkiji][@<href>{https://m2wasabi.hatenablog.com/entry/2018/06/26/122557}]

== アバターを手にするまで

VR空間に着ていくアバターをすべての人が自作出来ればいいのですが、モデリングは人類の基本スキルではないようです。
モデルを自作できない人は人様のモデルを拝借するわけですが、心して、以下の点は絶対に気を付けましょう。

 * @<b>{権利的にクリアであること}（Unityでの利用が許可されている、アバターで使ってもOKである、n次創作ではないなど）

守れないと金銭的被害や創作ライフ終了に繋がるので、冗談では済まされません。

今回チュートリアルで用いるのは、あいんつさん（@<href>{https://twitter.com/einz_zwei,@einz_twei}）のアークトラスちゃん@<fn>{3.avatar.arctrus}です。  

//image[shop_flyer][アークトラス（ショップのフライヤーより）][scale=0.5]

//footnote[3.avatar.arctrus][@<href>{http://www.melonbooks.com/index.php?main_page=product_info&products_id=IT0000204181}]

アークトラスちゃんは以下の点でVRMのチュートリアルを行うのに適しています。  

 * 揺れモノを仕込まなくても不都合が無い
 * ポリゴン数が控えめ
 * Humanoidをセットアップしやすい（Unityで読み込むことが出来るfbx同梱)
 * カスタマイズしやすい

マテリアルやテクスチャ数がだいぶ絞ってあり、MMDerよりもゲの付く業界の人が作った感じでUnityで使いやすいです。  
ユニティちゃんシェーダ2の作例としても優れていて、参考になります。  

そして何よりも価格がお手頃（1080円）というところです。

== プロジェクトを用意する

バーチャルキャストや自作のアプリで動かしたい場合は、特に何も考えずVRMのドキュメントに従えばセットアップ可能です。
以下、モデルに依存した細かい部分について説明します。

まずはUnityで新規プロジェクトを作成し、UniVRM@<fn>{3.univrm}をインポートします。
//footnote[3.univrm][UniVRM：@<href>{https://github.com/dwango/UniVRM/releases}]

== FBXデータの読み込み

Asset内の適当なフォルダにfbxをインポートしましょう。
//image[u001][FBXのインポート][scale=0.5]

== VRM用のマテリアルを作成する

アークトラスちゃんのマテリアルはユニティちゃんトゥーンシェーダ2でセットアップされています。
自作のアプリなどで、対応するシェーダを先に読み込ませておけば、何も考えずにVRM化して無事読み込めるのですが、
そうでない場合、VRMの基本的なシェーダでマテリアルをセットアップしなおさなければいけません。

今回は、マテリアルをMToonに置き換えます。
元のマテリアルは@<b>{head}, @<b>{main}, @<b>{armor} の3種類なので、変換後のマテリアルも同様の名前で3種類用意しましょう。
prefabを2体並べて比較しながら調整するとよいでしょう。

//image[u002][prefabを並べる][scale=0.5]

VRM用のマテリアルを作成して  
//image[u003][MToon用マテリアルの作成][scale=0.5]

片方のprefabに適用します。
//image[u004][マテリアルの適用][scale=0.5]

リムライトがなかったりMatCapの当たり方が異なったり、ベースカラー適用のロジックが異なったりするので、
全く同じに再現するのは難しいので、大体違和感がない程度に調整します。

調整を完了すると、見た目がおおよそ揃います。
//image[u005][マテリアルの調整][scale=0.5]

セットアップ例を示します。
カラーの設定値は @<table>{material_colors} となりますが、弊紙面からスポイト機能を使って直接設定すると楽です。

//image[u006][マテリアルの詳細]

//table[material_colors][マテリアルのカラー]{ 
.	Lit & Alpha	Shade	Emission
------------------
Armor	FFFFFF	E2E2E2	C8C8C8
Head	FFFFFF	FFE5C4	000000
Main	FFFFFF	E5D89E	000000
//}

== 最初のVRMエクスポート

VRMのマテリアルを適用したモデルをVRMに変換します。  

VRM置き場(フォルダ)を用意して

//image[u007][VRM用フォルダの作成][scale=0.5]

Hierarchy上のモデルを選択した状態で、エディタのメニューから @<b>{VRM} > @<b>{export humanoid} を開きます。

//image[u008][初めてのVRMエクスポート][scale=0.5]

名前と作者名を入力して、@<b>{Force T Pose} と @<b>{Pose Freeze} にチェックが入った状態でインポートを実施しましょう。

//image[u009][VRMの初期設定][scale=0.5]

途中NormalMapの変換のポップアップが出るので「Fix now」で変換してしまいます。
ここで何をしているかというと、ノーマルマップの座標を3軸から2軸+1軸推定に変換しているようです@<fn>{3.normaimap_convert}。
//footnote[3.normaimap_convert][@<href>{https://twitter.com/m_sigepon/status/1041294920420454400}]

//image[u010][ノーマルマップの変換][scale=0.5]

変換の結果、ノーマルマップの座標がおかしくなるので、Normal Map の数値を @<b>{0} に修正します。  

//image[u010-2][マテリアル Normai Mapの変更][scale=0.5]

== META情報の登録

== SpringBoneの調整




### メタ情報を入力する

変換したVRMのprefabをHieralchyに展開しましょう。  

[f:id:m2wasabi:20180626111308p:plain]

VRM Metaというスクリプトに、名前、作者情報、アバターの使用許諾条件などを記述しましょう。  
**Reference** の項目でサムネイル画像を設定できるのですが、楽するために下のプレビューから画像を切り取って貼ってしまいました。  

[f:id:m2wasabi:20180626111317p:plain]

### ファーストパーソンの時の描画設定

モデルによってはアバターにVRで入ったときに視界が顔の裏側で邪魔される場合があります。  
そんなときに顔の描画を消す処理を定義します。  
アークトラスちゃんの場合、腕輪がコントローラーの邪魔になるので、ファーストパーソンの時は腕輪も消えるように設定します。  

[f:id:m2wasabi:20180626051808p:plain]

### 表情をつける

VRM BlenｄShape Ploxyコンポーネントから Blend Shape Avatar をダブルクリックして  
BlendShapeEditorを開いて表情を定義していきます。  

[f:id:m2wasabi:20180626051851p:plain]

[f:id:m2wasabi:20180626051909p:plain]

### 目の動きをBlendShapeで行う

アークトラスちゃんは瞳の動きをBlendShapeで定義しているので、  
`VRM Look At Bone Appluer` を `VRM Look At Blend Shape Appluer` に差し替えます。   

VRM Look At Blend Shape Appluer を読み込んで  
[f:id:m2wasabi:20180626052014p:plain]

VRM Look At Bone Appluer を削除します  
[f:id:m2wasabi:20180626052030p:plain]

### 2回目のVRMコンバート(仕上げ)

セットアップが完了したので、VRMのprefabをApplyし、再度VRMエクスポートを実行します。

[f:id:m2wasabi:20180626111424p:plain]

### ビュアーで見てみよう

VRMのサンプルプロジェクトに、VRMキャラクターのビュワーがあるので  
インポートして実行してみましょう。  

`UniVRM-RuntimeLoaderSample-0.38.unitypackage` をプロジェクトに展開し、  
シーン `VRMViewer` を読み込んで実行します。  

[f:id:m2wasabi:20180626052257p:plain]

動いた！  

[f:id:m2wasabi:20180626113003p:plain]

### バーチャルキャストで連携する

これでニコニ立体にアップすれば、バーチャルキャストに連携することもできます。  
再配布が禁じられているモデルの場合、アップロードして下書きのまま運用すれば、  
ニコニ立体の一覧に表示されないので、活用しましょう。  

[f:id:m2wasabi:20180626105939p:plain:w300][f:id:m2wasabi:20180626105947p:plain:w300]


バーチャルキャストの設定方法は、以下を参照ください。  

[https://www.infiniteloop.co.jp/blog/2018/04/virtualcast-matsui/:embed:cite]

## cluster.対応 VRMセットアップ

アークトラスちゃんの真価は、制限に強いところだと言えます。  
ポリゴン数控えめで、物理無くても困らないので、  
 cluster. などの制限フルなプラットフォームへの対応コストが劇的に低く、  
ロー or ミドルポリゴン向けの環境にも、特にメッシュを落とさずに入っていけます。  

### 要件を確認する

cluster. で動かすためのVRMアバターは結構制限が厳しいです。  

| 要素 | 上限 |
| --- | --- |
|ファイルサイズ|25MB|
|GameObjectの数|256|
|ポリゴン数|32000|
|メッシュの数|16|
|サブメッシュを含めたメッシュ数の合計|32|
|ブレンドシェイプの数|64|
|ボーンの数|128|

> 参照元：[https://clustervr.gitbook.io/sdk/avatar_customization/avatar_limit:title]

### cluster. SDKでインポートしてみる

cluster. で使うアバターをセットアップするのに、 cluster. SDK があれば便利です。  
中身はVRMにアバターチェック、アップロード機能が追加されたものです。  
セットアップは以下のリンクを参照してください。(SDKダウンロードのリンクもそこにあります)  

[https://clustervr.gitbook.io/sdk/getting_started:title]

cluster. SDK の推奨バージョンは **Unity 2017.4** です。  
他のバージョンでも動きそうではありますが念のため合わせておくと確実です。  

新規プロジェクトにcluster. SDKを読み込み、  
モデルを変換しようとすると、  
問題がある場合は、写真のように問題がある箇所を指摘されます。  
なお問題ない場合はそのまま変換されます。  
やってみよう！  

[f:id:m2wasabi:20180625133756p:plain:w300]

今回はメッシュの数が1つ多いようです。  
つまりやるべき作業は、 **メッシュの統合を行って数を減らす** ということです。  

### blenderでメッシュを統合する

blederでfbxを読み込ませます。  
設定はこんな感じで。  

[f:id:m2wasabi:20180626083752p:plain:w250][f:id:m2wasabi:20180626083808p:plain:w250]

軸設定が大事で、以下のように設定します。  
Main が `-Z Forward` , `Y Up`  
Armatures が `Primary Y Axis`, `Secondary X Axis`  

cluster.の基準に入るには  
メッシュを一つ統合すれば済みます。  
あとで得物とかギミックを仕込めるように、もう少し統合しておきましょう。  
背骨のアーマーとブーツをそれぞれまとめます。  

統合事故を避けるために編集したいメッシュ以外非表示にしましょう。  

[f:id:m2wasabi:20180626022917p:plain]


`Shift` キーを押しながら統合したいメッシュを選択して、左の `Join` ボタンで統合します。  

[f:id:m2wasabi:20180626030701p:plain]

ブーツも同様に統合します。  

[f:id:m2wasabi:20180626030803p:plain]

名前をシンプルに変えます。  

[f:id:m2wasabi:20180626030825p:plain]

仕上げにfbxに書きだします。

[f:id:m2wasabi:20180626030925p:plain:w300]

fbx書き出しの設定はこのようにします。  
軸設定は、インポート時と同じにしましょう。  
あと注意する点としては、 `Path Mode : COPY` にする `Add Leaf Bones は OFF` とかです。  

[f:id:m2wasabi:20180626084242p:plain:w200][f:id:m2wasabi:20180626031001p:plain:w200][f:id:m2wasabi:20180626084329p:plain:w200][f:id:m2wasabi:20180626031010p:plain:w200]


### Humanoidのセットアップ

#### Unityにインポート

blenderから書き出したfbxをUnityに読み込ませます。  
変更前のファイル一式もプロジェクトにインポートしておきます。  

#### Rig

3DモデルデータをUnityにインポートするとき、ボーンやテクスチャの設定が必須なのですが、  
アークトラスちゃんはボーン名がローマ字読みで入っていて辞書で解決されないので、ボーンの設定が面倒です。    
そこで先に変更前のモデルのアバター定義を **HumanTemplate** ファイルとして保存して、読み込ませます。  

変更前のfbxを開いて、 `Rig` の設定から **Avatar Definition** → ✓ `Configure...` をクリックします。  

[f:id:m2wasabi:20180626084823p:plain:w250]

アバターのボーン設定メニューになるので、下の `Mapping` から `Save` で保存します。  

[f:id:m2wasabi:20180626085410p:plain:w250]

次に変更後のfbxに保存した **HumanTemplate** ファイルを読み込ませて `Rig` の設定は完了です。  

#### Main

`Main` は変更前のfbxの真似でOKです。  
[f:id:m2wasabi:20180626090115p:plain]

#### Materials

`Materials` は、既にVRM用のマテリアルを定義済みだと思うので、それを適用します。  
[f:id:m2wasabi:20180626090328p:plain]

### Prefabの作成

Hierarchyに変更したモデルを設置すると、変更前とツリー構造が異なっていることに気が付きます。  
[f:id:m2wasabi:20180626090833p:plain]

散らかって分かりにくいので元のツリー構造と同じに設定します。  
[f:id:m2wasabi:20180626091100p:plain]

`*_ALLG`とかいう謎の追加オブジェクトは削除してしまいましょう。  

モデルをプロジェクトディレクトリにドロップして Prefab 化します。  

### VRMの作成(2回目)

Hierarchy上のPrefabをVRMに変換します。  
以降は前述のVRMセットアップと同じ内容なので省略します。  
そんなわけでメタ情報や表情の設定を同様にやりなおして完成です。  

### cluster. にアップロードする

`cluster. SDK` のメニューからアバターをアップしてみましょう。  
[f:id:m2wasabi:20180626110322p:plain:w300]

<span style="font-size: 200%">MANZOKU</span>  
[f:id:m2wasabi:20180626121040p:plain]


== 応用編：様々なプラットフォームで使うために

=== Unityとblenderの往復

Unityで利用するモデルに編集を加えて、再びUnityに戻す作業は、注意する点を知らないと嵌りがちです。

==== 編集の基本：Unity用FBXからblenderへ

==== 編集の基本：blenderからUnity用FBXへ

==== 編集の基本：FBXのインポートとHumanoid

=== 容量削減：首から上のオブジェクトを分離する

=== 容量削減：テクスチャを圧縮する

=== 制約対策：ポリゴン数の削減

=== 制約対策：マテリアル数の削減

=== 制約対策：ボーン数追加・削除

・VRoidで生成したVRMで髪を揺らしたい
VRoidのモデルは髪型を自由に作れますが、ボーンは入っていません。
髪を揺らしたい場合、髪型に対応したボーンを追加し、ウェイトを設定しなければいけません。

・ボーン数がアプリケーションの制限を超えたとき
登録されるVRMファイルにボーン数の制限があるアプリケーション
例えばclustar

参考
VRoidモデルの髪を揺らしてみたい！（前編）
https://aozoranositade.ape.jp/?p=1997
