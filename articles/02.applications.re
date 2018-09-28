= VRMに対応したアプリケーション

VRMはオープンな仕様です。

※カテゴリ内の順番はリリース日時順です。

#@# wiki

#@# @<href>{http://pc-vr.game-info.wiki/}



== 2大つよつよアプリ

先行してVRMを実用し、経済を回しているアプリです。

=== バーチャルキャスト
開発元：株式会社バーチャルキャスト @<br>{}
プラットフォーム：Windows @<br>{}
URL：@<href>{https://virtualcast.jp/} @<br>{}

最初にして最強のVRMアプリです。
ニコニコ動画を拡張した実験放送に対応し、3Dアバターで生配信・凸できます。
みゅみゅ氏の開発したバーチャルコスプレ生放送システムが元になっています。

コメント送信やTwitter連携、カメラ、ホワイトボードなど各種アイテムの完成度が高く他の追随を許さないクオリティです。
VR環境が必須で、HTC Vive 10点トラッキング対応などコストをかければかけるほど体験の質が上がります。Viveフルトラはバーチャル上流階級の嗜みです。
もちろん、Oculus Riftや WindowsMR を用いても十分な体験を得られます。

最近だと、バーチャルキャストと共に『ワールドビジネスサテライト』『スッキリ』でTV紹介されました。
どちらもリポーターの方を虜にしていて、既存の価値観を変えてきてるのが印象的でした。


=== cluster
開発元：クラスター株式会社 @<br>{}
プラットフォーム：Windows, Mac @<br>{}
URL：@<href>{https://cluster.mu/} @<br>{}

『引きこもりを加速する』を合言葉にしているバーチャル会議プラットフォーム cluster は、VRMの発表からいち早くアバターのVRM対応を行いました。
月ノ美兎の公式生放送、ファイ博士の28時間放送、輝夜月のZeppVR Live を経て、大型イベントによって機能の拡張を繰り返しています。
clusterはVRMのアバターをアップするための制約が多く、アップするために多少の調整が必要になる場合があります。
@<href>{https://clustervr.gitbook.io/sdk/avatar_customization/avatar_limit}


== アバターメイカー

== Vカツ
開発元：IVR @<br>{}
プラットフォーム：Windows @<br>{}
URL：@<href>{http://vkatsu.jp/} @<br>{}

パーツを組み合わせてアバターを作るタイプのアバター作成アプリです。
ニコニ立体と連携することで、作成したアバターをバーチャルキャストで使用することができます。

割と公然の秘密ですが、元々「コイカツ」という18禁ゲームがあって、そのエイプリルフールネタが現実になってしまったものです。
当然ですが、全年齢化に伴い、えっちな装備は削除されています。

なお、自作のアバターをバーチャルキャストで使用するには、キャラクターの投稿枠を購入する必要があります。
キャラクターの投稿枠はひとつにつき5,000円です。


== VRoid Studio
開発元：ピクシブ株式会社 @<br>{}
プラットフォーム：Windows, Mac @<br>{}
URL：@<href>{https://vroid.pixiv.net/} @<br>{}



== ビュワー

=== UniVRMTest
作者：ousttrue @<br>{}
URL：@<href>{https://github.com/dwango/UniVRMTest} @<br>{}

ドワンゴさんのUniVRMの公式サンプルです。
モーションを読み込んでアニメーションとMETA情報の確認ができます。

基本的なランタイムロードのやり方はほぼこのサンプルのコピペで導入することができます。

※付録
拙作のUniVRMのサンプルをDaydream用にコンパイルしたものを配布しています。
MirageSoloなどのDaydream端末をお持ちでしたら、VRMモデルをVRで見ることができます。

=== VRMビュアー
作者：ビームマンP @BeamManP @<br>{}
プラットフォーム：Windows @<br>{}
URL：@<href>{https://www43.atwiki.jp/beamman/} @<br>{}

サンプルを除いて、個人勢で最も早く公開されたアプリです。
VRMをロードしてUnityちゃんのモーションを確認できるます。

=== VRM Live Viewer

作者：ヽ｜∵｜ゝ(Fantom) @<br>{}
プラットフォーム：Windows, Android @<br>{}
URL：@<href>{http://fantom1x.blog130.fc2.com/blog-entry-309.html} @<br>{}

UnityちゃんのCandyRockStarがデモで入っているVRMビュワーです。
BVHインポート機能があったり、ビュワーの中ではもっとも高機能です。

=== VPocket

作者：ほーのき @booooooh522 @<br>{}
プラットフォーム：iOS, Android @<br>{}
URL：@<href>{https://twitter.com/booooooh522/status/1031548305317093376} @<br>{}

@<href>{https://play.google.com/store/apps/details?id=com.BooApps.VPocket}
@<href>{https://itunes.apple.com/jp/app/vpocket-vrm-viewer/id1426245522?mt=8}

iOS、Androidに対応したVRMビュワーです。
ポーズや表情を手動で設定して撮影するアプリで、
VRMモデルをARで表示させることができます。
体のポーズはIKで編集し、手のポーズはプリセットから選択。
表情を編集するUIが面白いのが特徴です。
アクティブなモーションには対応していませんが、それを差し引いてもARモードが良いです。
自分のアバターを外に持ち出してインスタバエするのにはお勧めです。


=== UniWinApiVrmViewer
作者：キルロボ @kirurobo @<br>{}
プラットフォーム：Windows @<br>{}
URL：@<href>{https://github.com/kirurobo/UniWinApi} @<br>{}

透過ウインドウに対応したVRMビュワーです。
デスクトップマスコットアプリのスキャフォールディングを目指してそうなプロジェクトです。
UniWinApi & Example projectというプロジェクトの一部です。
WindowsAPIを明確に使用しているので、Windows以外への移植は難しそうです。

== 動画配信用アプリ

=== 3tene
開発元：株式会社 プラスプラス @<br>{}
プラットフォーム：Windows @<br>{}
URL：@<href>{https://3tene.com/} @<br>{}


=== VDRAW
URL：@<href>{https://sites.google.com/view/vdraw/} @<br>{}
作者：おぐら @OGOG_Ogur @<br>{}
プラットフォーム：Windows @<br>{}

お絵描き配信に特化したアプリです。
基本動作は、画面のミラーがウィンドウ内に表示され、マウスポインタをペンを持ったアバターが追いかけます。
音声入力からのリップシンク、背景の変更、画面キャプチャ範囲の変更など、
おおよそお絵描き配信に必要な機能は不足なく実装されています。
個人製作のVRM対応アプリとしての完成度はトップクラスです。

=== バーチャルモーションキャプチャ―
URL：@<href>{https://github.com/sh-akira/VirtualMotionCapture} @<br>{}
作者：あきら @sh_akira @<br>{}
プラットフォーム：Windows @<br>{}

配信中画面にアバターの動きを合成するためのアプリです。
これによってあたかも自分のアバターがゲーム内に入ったかのような映像が得られます。
現在βながら、個人配信者に非常に人気の高いアプリです。

== ゲームアプリ

=== Vワールド
作者：  @7u_NABY @<br>{}
プラットフォーム：Windows @<br>{}
URL：@<href>{https://twitter.com/7u_NABY/status/1033699969289543682} @<br>{}

自撮り＋ワールドクリエイションみたいなアプリです。
VRMキャラで街のフィールドを歩き回ったり、オブジェクトを設置したりできます。
光源の設定が細かく、スクリーンショットには独特の味があります。
ワールドをシェアできるプラットフォームを開発中らしいです。
また、VRoid Hub発表時に、個人勢で唯一API対応を謳っているアプリです。
本書が出回る頃には具体的情報が出ている気がします。
けもフレRPGの作者。

== ツール

=== xismo
作者：mqdl @<br>{}
プラットフォーム：Windows @<br>{}

個人開発の3Dモデリングツールです。
現時点ではVRMの読み込みのみ対応しています。

@<href>{https://twitter.com/mqdl/status/1022747807646539776} @<br>{}
@<href>{https://twitter.com/mqdl/status/1028796028563025921} @<br>{}


== 現在開発中のもの

=== YOU ARE VTUBER!!
作者：なっつー @yashinut @<br>{}
URL：@<href>{https://www.youtube.com/watch?v=OOaPSN73V7E} @<br>{}

なっつー氏は、個人で様々なアプリを作られている方です。
『YOU ARE VTUBER!!』は過去に銀VRで展示、コミックマーケット94で頒布されました。
PC用のVR HMDを用いてモーションキャプチャ―を行い、キャラクターを演じるアプリです。
字幕台本や、モーションの遅延再生、スタンドアロンヘッドセットへの配信機能が特徴です。
VRMは対応はアップデートで対応される雰囲気です。
@<href>{https://twitter.com/yashinut/status/1022881662550458368}
アプリを入手する機会が非常に限られていますが、イベントなどで入手した人は楽しみにアップデートを待ちましょう。

他にも、アバターとの思い出をねつ造する『想い出メーカー』や、
キャラクターに疑似言語でスピーチさせる『謎言語合成音声システム（仮）』などのVRM対応アプリのプロトタイプを多数作成されているので、今後が楽しみです。
@<href>{https://twitter.com/yashinut/status/1041704626930634753}
@<href>{https://twitter.com/yashinut/status/1044206458596810752}

=== karukaruとXX
作者：karukaru @_karukaru_ @<br>{}
URL：@<href>{https://com.nicovideo.jp/community/co70543} @<br>{}

ニコ生のコミュニティでVR空間を共有するアプリケーションやミニゲームを開発されています。
生放送の時限定で使えるアプリなどもあります。生放送時か正式リリースを待ちましょう。

=== BabiSenGO
作者：やのせん @yanosen_jp @<br>{}
プラットフォーム：OculusGo @<br>{}
URL：@<href>{https://twitter.com/yanosen_jp/status/1041484658905571328} @<br>{}

OculusGoでプレゼンテーションを録画するシステムを開発中です。
完成すればアバターによるウェビナーが急激に民主化するのではないでしょうか。

== Vカーソル
作者：えもこ @emoco_art @<br>{}
URL：@<href>{https://www.youtube.com/watch?v=jJls7xFXw3s} @<br>{}

== Unity以外のプラットフォーム

=== THREE.js
URL：@<href>{https://threejs.org/examples/?q=VRM#webgl_loader_vrm} @<br>{}

WebGLライブラリの中で一番使われているライブラリ。
もともとglTF2.0のロードには対応していたので、その流れでVRMに対応している。
物理演算やMETAプロパティの読み込みには非対応です。
利用条件が読み込めないので、自前サービスで使いたい場合は気を付けましょう。

==== FaceVTuber
URL：@<href>{https://facevtuber.com/} @<br>{}
作者：FaceVTuberOfficial @FaceVTuber @<br>{}
プラットフォーム：web @<br>{}

ブラウザ上で顔認識を行い顔追従を行うFaceRigのようなwebサービス。
PMDやFBXと同様にVRMも読み込むことが可能。
THREE.jsでさくっと読み込めるしせっかくだから付けたというおまけ感ある。

==== VRM Three.js AR Sample

URL：@<href>{https://twitter.com/t_takasaka/status/1036235629741260800} @<br>{}
作者：高坂 @t_takasaka @<br>{}

VRMをWebブラウザでAR表示させるサンプルです。

==== VRM Three.js PoseNet Sample
URL：@<href>{https://github.com/t-takasaka/vrm-three-posenet} @<br>{}
作者：高坂 @t_takasaka @<br>{}

THREE.jsとPoseNetを使って動画からVRMにモーションを転写するサンプルコードです。

==== Teraconnect

URL：@<href>{https://authoring.teraconnect.org/} @<br>{}
開発元：Teraconnect @<br>{}

ブラウザ上でアバターによるウェビナーを作ることが出来るウェブサービスです。
スライド画像をアップロードしてスライドの操作をしながらトークを進めていくことで授業ができあがります。
音声から文字起こしや、アバターの口パクが行われます。
現在はβ運用中で、授業が10日で自動的に消えてしまいます。

=== UnrealEngine4 での VRMランタイム

悩ましい状況が続いています。
UE公式がglTFへの対応予定を謳っています。
@<href>{https://trello.com/b/omtMIw06/gltf-for-ue4}
また、OSSのgiTFローダーのプロジェクトもあります。
@<href>{https://github.com/code4game/glTFForUE4/}
しかしながら、VRMに特化してローディグ環境を完成させたという報告はまだありません。
UETokyoのプロジェクトを推進するか、glTFForUE4をフォークして作る人しかありません。
@<href>{https://github.com/uetokyo/UnrealVRM}
