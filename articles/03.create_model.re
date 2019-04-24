= VRMモデルの制作ワークフロー


== VRMモデルのセットアップ

この章ではFBXモデルからVRMモデルのコンバート・調整の手順を解説していきます。
内容的には弊ブログの記事@<fn>{3.link.blogkiji}に、SpringBoneやモデルの調整を追加したものになります。

//footnote[3.link.blogkiji][@<href>{https://m2wasabi.hatenablog.com/entry/2018/06/26/122557}]

=== アバターを手にするまで

VR空間に着ていくアバターをすべての人が自作出来ればいいのですが、モデリングは人類の基本スキルではないようです。
モデルを自作できない人は人様のモデルを拝借するわけですが、心して、以下の点は絶対に気を付けましょう。

 * @<b>{権利的にクリアであること}（Unityでの利用が許可されている、アバターで使ってもOKである、n次創作ではないなど）

守れないと金銭的被害や創作ライフ終了に繋がるので、冗談では済まされません。

今回チュートリアルで用いるのは、あいんつさん@<fn>{3.twitter.einz}のアークトラスちゃん@<fn>{3.avatar.arctrus}です。  

//image[shop_flyer][アークトラス（ショップのフライヤーより）][scale=0.5]

//footnote[3.twitter.einz][@<href>{https://twitter.com/einz_zwei,@einz_twei}]
//footnote[3.avatar.arctrus][@<href>{http://www.melonbooks.com/index.php?main_page=product_info&products_id=IT0000204181}]

アークトラスちゃんは以下の点でVRMのチュートリアルを行うのに適しています。  

 * 揺れモノを仕込まなくても不都合が無い
 * ポリゴン数が控えめ
 * Humanoidをセットアップしやすい（Unityで読み込むことが出来るfbx同梱)
 * カスタマイズしやすい

マテリアルやテクスチャ数がだいぶ絞ってあり、MMDerよりもゲの付く業界の人が作った感じでUnityで使いやすいです。  
ユニティちゃんシェーダ2の作例としても優れていて、参考になります。  

そして何よりも価格がお手頃（1080円）というところです。

=== プロジェクトを用意する

バーチャルキャストや自作のアプリで動かしたい場合は、特に何も考えずVRMのドキュメントに従えばセットアップ可能です。
以下、モデルに依存した細かい部分について説明します。

まずはUnityで新規プロジェクトを作成し、UniVRM@<fn>{3.univrm}をインポートします。
//footnote[3.univrm][UniVRM：@<href>{https://github.com/vrm-c/UniVRM/releases}]

=== FBXデータの読み込み

Asset内の適当なフォルダにfbxをインポートしましょう。
//image[u001][FBXのインポート][scale=0.5]

=== VRM用のマテリアルを作成する

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

=== 最初のVRMエクスポート

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

=== META情報の登録

変換したVRMのprefabをHieralchyに展開しましょう。  

//image[u013][VRMをHierarchyに展開する]

VRM Metaというスクリプトに、名前、作者情報、アバターの使用許諾条件などを記述しましょう。
@<b>{Reference} の項目でサムネイル画像を設定できるのですが、楽するためにInspectorのプレビューから画像を切り取って貼ってしまいました。

//image[u014][META情報を設定する][scale=0.5]

=== ファーストパーソンの時の描画設定

モデルによってはアバターにVRで入ったときに視界が顔の裏側で邪魔される場合があります。
そんなときに顔の描画を消す処理を定義します。
アークトラスちゃんの場合、主観で見ると腕輪が視界の邪魔になるので、ファーストパーソンの時は腕輪も消えるように設定します。

//image[u015][VRM First Person の設定][scale=0.5]

=== 表情をつける

VRM BlenｄShape Ploxyコンポーネントから Blend Shape Avatar をダブルクリックして  
BlendShapeEditorを開いて表情を定義していきます。  

//image[u016][VRM BlenｄShape Ploxy][scale=0.5]
//image[u017][BlendShapeEditor][scale=0.5]

=== 目の動きを設定する

目の動きは、モデルによってBoneが割り当てられていたり、BlendShapeで動かす場合があります。
Boneで割り当てられている場合、Humanoidの設定で適切にボーンをせっていしておけば、特に特にすることはありません。
しかし、目の動きがBlendShapeで割り当てられている場合は、@<b>{VRM Look At Applyer}の差し替えが必要になります。


==== 目の動きがBlendShapeの場合

アークトラスちゃんは瞳の動きをBlendShapeで定義しているので、
VRMコンポーネント内の @<b>{VRM Look At Bone Applyer} を @<b>{VRM Look At Blend Shape Appluer} に差し替えます。

//image[u020][VRM Look At Blend Shape Applyer の登録][scale=0.5]
//image[u021][VRM Look At Bone Applyer の削除][scale=0.5]

=== SpringBoneの調整

VRMの揺れ物は、@<b>{VRMSpringBone}で定義されます。
@<b>{VRMSpringBone}は、VRMオブジェクトの下の secondary というオブジェクトに付いています。

//image[u033][VRMSpringBone][scale=0.5]

VRMSpringBoneのプロパティは次のようになっています。

//table[VRMSpringBone][VRMSpringBoneのプロパティ]{ 
name	説明
------------------
Gizmo	当たり判定をSceneに表示する設定。挙動のデバッグ用
Stiffness Force	剛性。高いほど動きにくい
Gravity Power	重力の強さ。今のVRMに1は強すぎる
Drag Force	抗力。摩擦係数ともいわれる。高いとすぐに減衰する
Root Bones	SprngBoneの根っこ。ここから末端に向けての全てのボーンが揺れる。複数指定可能
Hit Radius	SpringBoneの当たり判定の半径
Colider Groups	このSpringBoneで扱うコライダーリスト
//}

一つの@<b>{VRMSpringBone}に全ての揺れものが入っていると、揺れの属性はすべて同じになってしまいます。
VRMは、単一のsecondaryに、複数の@<b>{VRMSpringBone}コンポーネントを定義することができます。
揺れの属性が異なる揺れ物は、別々のコンポーネントに格納して、バリエーションを持たせることができます。

==== 揺れ物を付けてみる

早速、揺れものを付けてみましょう。
アークトラスちゃんの揺れそうな部位は、ポニーテールだけです。

トランスフォーム ponite_root を Root Bones に入れてみましょう。

//image[u034][Root Bonesをセット][scale=0.5]

//image[u035][揺れ物のテスト][scale=0.3]

簡単にセットできました。

==== コライダーを付けてみる

このままでもいいのですが、後ろに下がるときに、ポニーテールが頭にめり込んでしまいます。
そこで、頭にコライダーを設置してめり込みを防ぎましょう。

トランスフォーム head_j に @<b>{VRMSpringBoneColliderGroup} コンポーネントを追加します。

//image[u036][VRMSpringBoneColliderGroup][scale=0.5]

VRMSpringBoneColliderGroup は、コンポーネントの中に複数の球状の Collider を定義できます。
Colliderは@<b>{Offset}で位置を、@<b>{Radius}で当たり判定の径を定義できます。
たくさんつなげれば疑似的に棒状の当たり判定にすることも可能です。

//image[u037][VRMSpringBoneColliderGroup をセット][scale=0.5]

=== 2回目のVRMエクスポート（仕上げ）

セットアップが完了したので、VRMのprefabをApplyし、再度VRMエクスポートを実行します。
任意の場所にVRMを吐き出しましょう。

//image[u019][仕上げのVRMエクスポート][scale=0.5]

=== ビュアーで見てみよう

VRMのサンプルプロジェクトに、VRMキャラクターのビュワーがあるので  
インポートして実行してみましょう。  

@<b>{UniVRM-RuntimeLoaderSample} @<fn>{3.univrm}をプロジェクトに展開し、  
シーン `VRMViewer` を読み込んで実行します。  

//image[u022][UniVRM-RuntimeLoaderSample のインポート][scale=0.5]

//image[u023_2][VRMViewer を動かして読み込む]

動いた！完成です！

=== バーチャルキャストで連携する

これでニコニ立体にアップすれば、バーチャルキャストに連携することもできます。  
再配布が禁じられているモデルの場合、アップロードして下書きのまま運用すれば、  
ニコニ立体の一覧に表示されないので、活用しましょう。  

//image[n001][ニコニ立体へのアップ][scale=0.5]
//image[n002][下書き運用で非公開][scale=0.5]

バーチャルキャストでのニコニ立体モデルの使用方法は、以下を参照ください。  

@<href>{https://www.infiniteloop.co.jp/blog/2018/04/virtualcast-matsui/}


== 応用編：様々なプラットフォームで使うために

=== Unityとblenderの往復

アプリで利用する際に、アップロードできるモデルに何らかの制限が掛かっている場合があります。
その対応をするには、Unity外のモデリングツール（Maya, blenderなど）で編集して再インポートする必要があります。

Unityで利用するモデルに編集を加えて、再びUnityに戻す作業は、注意する点を知らないと嵌りがちです。

ここでは、blenderを例に挙げてモデルの編集とUnityへ戻すことを見ていきます。

==== 編集の基本：Unity用FBXからblenderへ

blederでfbxを読み込ませます。
このとき、軸設定が大事で、次のように設定します。

 * Main が @<b>{-Z Forward} , @<b>{Y Up}
 * Armatures が @<b>{Primary Y Axis}, @<b>{Secondary X Axis}

//image[b004][blenderのFBX取り込み時の設定][scale=0.5]

==== 編集の基本：blenderからUnity用FBXへ

blenderからのfbx書き出しをします。

//image[b008][blenderのFBX書き出し][scale=0.5]

軸設定は、インポート時と同じにしましょう。
あと注意する点としては、次の項目です。

 * @<b>{Path Mode ： COPY}
 * @<b>{Add Leaf Bones ： OFF}

//image[b009][blenderのFBX書き出し時の設定]

==== 編集の基本：FBXのインポートからのHumanoidセットアップ

===== Unityにインポート

blenderから書き出したfbxをUnityに読み込ませます。  
変更前のファイル一式もプロジェクトにインポートしておきます。  

===== Rig

3DモデルデータをUnityにインポートするとき、ボーンやテクスチャの設定が必須なのですが、  
アークトラスちゃんはボーン名がローマ字読みで入っていて辞書で解決されないので、ボーンの設定が面倒です。    
そこで先に変更前のモデルのアバター定義を @<b>{HumanTemplate} ファイルとして保存して、読み込ませます。  

モデル編集前のfbxを開いて、 @<b>{Rig} の設定から @<b>{Avatar Definition} → ✓ @<b>{Configure...} をクリックします。  

//image[u024][FBX import Rigの設定][scale=0.5]

アバターのボーン設定メニューになるので、下の @<b>{Mapping} から @<b>{Save} で保存します。  

//image[u025][HumanTemplateの保存][scale=0.5]

次にインポートしたfbxに保存した @<b>{HumanTemplate} ファイルを読み込ませて @<b>{Rig} の設定は完了です。  

===== Model

@<b>{Model} は変更前のfbxの真似でOKです。  
//image[u027-1][FBX import Modelの設定][scale=0.5]

===== Materials

@<b>{Materials} は、既にVRM用のマテリアルを定義済みだと思うので、それを適用します。  
//image[u027-6][FBX import Materialの設定][scale=0.5]

==== 編集応用編：モデルのツリー構造の変更

Hierarchyに変更したモデルを設置すると、変更前とツリー構造が異なっていることに気が付きます。  
使いづらい場合は変更しても問題ありません。ただし、ボーン構造は不用意に崩してはいけません。
//image[u028][変わってしまったツリー構造][scale=0.5]

散らかって分かりにくいので元のツリー構造と同じに設定します。  
//image[u028-2][ツリー構造を元に戻す][scale=0.3]

@<b>{*_ALLG}とかいう謎の追加オブジェクトは削除してしまいましょう。  

モデルをプロジェクトディレクトリにドロップして Prefab 化します。  

=== blenderでのモデル調整

本格的な使い方は専門書@<fn>{3.blender.benjamin}や動画@<fn>{3.blender.wani}に譲るとして、ここでは、出来合いのモデルを調整するTipsを掲載します。

//footnote[3.blender.benjamin][Blender 3DCG モデリング・マスター ISBN-13: 978-4800711472]
//footnote[3.blender.wani][@<href>{https://www.youtube.com/watch?v=7oNfgOOcKm8&list=PLh2HlgtpWBpW9ZRP5uIhIfyMgtHT41Mai,ワニでもわかるゼロからのBlender}]

==== 制約対策：メッシュの統合

メッシュの数が多い場合、メッシュを統合することになります。

アークトラスちゃんのメッシュは細かめに分かれているので、これ一個でいいと思う部分は統合してしまいましょう。
あとで得物とかギミックを仕込めるように、余裕をもって統合しておきましょう。  
背骨のアーマーとブーツをそれぞれまとめます。  

//image[b005][blenderで読み込み][scale=0.5]

統合事故を避けるために編集したいメッシュ以外非表示にしましょう。  

//image[b006][統合メッシュのみ表示][scale=0.5]


@<b>{Shift} キーを押しながら統合したいメッシュを選択して、左の @<b>{Join} ボタンで統合します。  

//image[b007_kai][メッシュの統合][scale=0.5]

ブーツも同様に統合します。  

//image[b007-2][メッシュの統合2][scale=0.5]

名前をシンプルに変えます。  

//image[b007-2b][メッシュ名の単純化][scale=0.5]

==== 容量削減：顔のオブジェクトを分離する

VRMはBlendShapeの情報を保持するために、該当のメッシュの複製を記録します。
ここで、動かすメッシュの頂点数が多いほど、BlendShapeを追加した場合のVRM容量は増えます。

頭を含む体全体で一つのメッシュを設定した場合、表情一つごとに、体全体の複製が作られて、VRMファイルは数十MBになったりします。

これを避けるために、表情をつかさどる顔のメッシュは分離するのが得策です。

@<b>{Edit Mode}に変更して、分離したいオブジェクトを選択して @<b>{[P] キー} を押すと分離メニューが出るので、@<b>{By Material} を選択して分解します。
ここでは、サンプルとして、FBXのメッシュが統合されている社畜ちゃん@<fn>{3.model.shachikuchan}のモデルに登場してもらいます。
//footnote[3.model.shachikuchan][@<href>{http://3d.nicovideo.jp/works/td35849}]

//image[b011][Edit Mode][scale=0.5]

//image[b012][Separate Menu][scale=0.5]

オブジェクトがマテリアルごとでバラバラになりました。

//image[b013][オブジェクトがバラけた][scale=0.5]

このままだとバラけすぎて辛いので、前節の手順でオブジェクトをある程度統合します。
統合するかはメッシュの非表示を使って統合部位を確認しながらJoinしていきます。

//image[b014-kai][オブジェクトの統合]

==== 制約対策：ポリゴン数の削減

モデルの制限事項で最たるものが、このポリゴン数でしょう。

Unity上で有料アセットのMesh Simplify@<fn>{3.asset.meshsimplify}を用いて減らしても良いでしょう。
しかし、BlendShapeをきれいに分離して、かつアプリの制約を突破しようと思うと、3Dモデリングツールで削減したほうがより確実に仕上がります。
//footnote[3.asset.meshsimplify][@<href>{https://www.assetstore.unity3d.com/#!/content/43658}]

BlendShapeがあるオブジェクトは、ポリゴン数を削減するとBlend削減するとが壊れるので、BlendShapeのかかっていない、体や大味な部品を重点的に削減します。

サンプルモデルは引き続き社畜ちゃんに出演してもらいましょう。
オブジェクトを選択し、スパナのアイコンをクリックすると@<b>{Modifier}という強力なフィルタ適用のメニューになります。
写真の例では髪を選択しています。
//image[b015][オブジェクトの統合][scale=0.5]

ここで、@<b>{Add Modifier}をクリックすると、たくさんのフィルタメニューが出ます。この中でポリゴン削減は @<b>{Decimate} または @<b>{ポリゴン数削減} という項目です。

//image[b016][ポリゴン数削減 を選ぶ][scale=0.5]

ポリゴン数削減メニューが出たら、@<b>{Ratio}の値をマウスドラッグで動かすと、下のFacesの値が変化します。このFacesが、選択オブジェクトの面数となります。

//image[b017][ポリゴン数削減 UI][scale=0.5]

ここで形が崩れないように注意しながら、良い感じにポリゴン数を減らしましょう。

最後に、@<b>{Apply} を押すと、ポリゴン数削減がメッシュに適用されます。

この作業を、オブジェクトごとに調整しながら行います。

==== 制約対策：ボーン数追加・削除

ボーン数を増減させるのは、とても面倒な作業です。
しかしながら、以下のケースでどうしても必要になってきます。

 * VRoidで生成したVRMで髪を揺らしたい

VRoidのモデルは髪型を自由に作れますが、ボーンは入っていません。
髪を揺らしたい場合、髪型に対応したボーンを追加し、ウェイトを設定しなければいけません。

 * ボーン数がアプリケーションの制限を超えたとき

例えばclustarのように登録されるVRMファイルにボーン数の制限があるアプリケーションで動かしたい場合。

さすがにこの工程はモデリングのセットアップに片足突っ込んでいて、ワークフローが膨大なので、先人のblog記事@<fn>{3.bone_add}を参考にしてください…

//footnote[3.bone_add][VRoidモデルの髪を揺らしてみたい！（前編）@<href>{https://aozoranositade.ape.jp/?p=1997}]

=== cluster.対応 VRMセットアップ

アークトラスちゃんの真価は、制限に強いところだと言えます。  
ポリゴン数控えめで、物理無くても困らないので、  
 cluster などの制限フルなプラットフォームへの対応コストが劇的に低く、  
ロー or ミドルポリゴン向けの環境にも、特にメッシュを落とさずに入っていけます。  

==== 要件を確認する

cluster. で動かすためのVRMアバターは結構制限@<fn>{3.cluster_avatar}が厳しいです。

//table[claster_limit][clusterのアバター制限]{ 
要素	上限
------------------
ファイルサイズ	25MB
GameObjectの数	256
ポリゴン数	32000
メッシュの数	16
サブメッシュを含めたメッシュ数の合計	32
ブレンドシェイプの数	64
ボーンの数	128
//}

//footnote[3.cluster_avatar][@<href>{https://clustervr.gitbook.io/sdk/avatar_customization/avatar_limit}]

==== cluster. SDKでインポートしてみる

cluster で使うアバターをセットアップするのに、 cluster. SDK @<fn>{3.cluster_sdk}があれば便利です。
中身はVRMにアバターチェック、アップロード機能が追加されたものです。
セットアップはSDKのリンク先を参照してください。（SDKダウンロードのリンクもそこにあります）

//footnote[3.cluster_sdk][@<href>{https://clustervr.gitbook.io/sdk/getting_started}]

cluster. SDK の推奨バージョンは @<b>{Unity 2018.1.1f1} です。  
他のバージョンでも動きそうではありますが念のため合わせておくと確実です。  

新規プロジェクトにcluster. SDKを読み込み、  
モデルを変換しようとすると、  
問題がある場合は、写真のように問題がある箇所を指摘されます。  
なお問題ない場合はそのまま変換されます。  
やってみよう！  

//image[b001][clasterアバターのチェック][scale=0.3]

今回はメッシュの数が1つ多いようです。  
つまりやるべき作業は、 @<b>{メッシュの統合を行って数を減らす} ということです。  

==== cluster にアップロードする

エラーが無くなったら、@<b>{cluster. SDK} のメニューからアバターをアップしてみましょう。  
//image[u032][clasterアバターのアップロード][scale=0.3]

//image[claster][clasterに侵入成功です][scale=0.5]
