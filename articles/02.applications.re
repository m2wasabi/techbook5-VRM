= VRMに対応したアプリケーション

VRMはオープンな仕様です。

※カテゴリ内の順番はリリース日時順です。

VRMの読み込み方法がワイルドすぎて実装とは呼べないやつはあえて取り上げません。
言わなくてもWakaruよな…？

== 2大つよつよアプリ

先行してVRMを実用し、経済を回しているアプリです。

=== バーチャルキャスト

最初にして最強のVRMアプリです。
ニコニコ動画を拡張した実験放送に対応し、3Dアバターで生配信・凸できます。
みゅみゅ氏の開発したバーチャルコスプレ生放送システムが元になっています。
コメント送信やTwitter連携、カメラ、ホワイトボードなど各種アイテムの完成度が高く他の追随を許さないクオリティです。
VR環境が必須で、HTC Vive 10点トラッキング対応などコストをかければかけるほど体験の質が上がるのですが、そのコストのせいで体験までの障壁が高いのが現状です。
もちろん、今値崩れの極みのWindowsMR ヘッドセットを用いても十分な体験は得られます。

=== cluster

『引きこもりを加速する』を合言葉にしているバーチャル会議プラットフォーム cluster は、VRMの発表からいち早くアバターのVRM対応を行いました。
月ノ美兎の公式生放送、ファイ博士の28時間放送、輝夜月のZeppVR Live を経て、大型イベントによって機能の拡張を繰り返しています。
clusterはVRMのアバターをアップするための制約が多く、アップするために多少の調整が必要になる場合があります。
https://clustervr.gitbook.io/sdk/avatar_customization/avatar_limit


== ビュワー

=== UniVRMTest
作者：ousttrue
https://github.com/dwango/UniVRMTest

ドワンゴさんのUniVRMの公式サンプルです。
モーションを読み込んでアニメーションとMETA情報の確認ができます。

基本的なランタイムロードのやり方はほぼこのサンプルのコピペで導入することができます。

※付録
拙作のUniVRMのサンプルをDaydream用にコンパイルしたものを配布しています。
MirageSoloなどのDaydream端末をお持ちでしたら、VRMモデルをVRで見ることができます。

=== VRMビュアー
作者：ビームマンP @BeamManP
https://www43.atwiki.jp/beamman/

VRMをロードしてUnityちゃんのモーションを確認できるアプリです。
余談ですが、作者の方はMMD使いには有名な方です。

=== VRM Live Viewer

作者：ヽ｜∵｜ゝ(Fantom)

http://fantom1x.blog130.fc2.com/blog-entry-309.html

UnityちゃんのCandyRockStarがデモで入っているVRMビュワーです。

=== VPocket

作者：ほーのき @booooooh522

https://twitter.com/booooooh522/status/1031548305317093376

https://play.google.com/store/apps/details?id=com.BooApps.VPocket
https://itunes.apple.com/jp/app/vpocket-vrm-viewer/id1426245522?mt=8

iOS、Androidに対応したVRMビュワーです。
ポーズや表情を手動で設定して撮影するアプリで、
VRMモデルをARで表示させることができます。
体のポーズはIKで編集し、手のポーズはプリセットから選択。
表情を編集するUIが面白いのが特徴です。
アクティブなモーションには対応していませんが、それを差し引いてもARモードが良いです。
自分のアバターを外に持ち出してインスタバエするのにはお勧めです。


=== UniWinApi & Example project
https://github.com/kirurobo/UniWinApi
作者：キルロボ @kirurobo

透過ウインドウに対応したVRMビュワーです。
デスクトップマスコットアプリのスキャフォールディングを目指してそうなサンプルプロジェクトです。
WindowsAPIを明確に使用しているので、プラットフォームはWindows専用です。

== 動画配信用アプリ

=== 3tene
URL：https://3tene.com/
開発元：株式会社 プラスプラス


=== VDRAW
URL：https://sites.google.com/view/vdraw/
作者：おぐら @OGOG_Ogur

=== バーチャルモーションキャプチャ―
URL：https://github.com/sh-akira/VirtualMotionCapture
作者：あきら @sh_akira

== ゲームアプリ

=== Vワールド
作者：  @7u_NABY
https://twitter.com/7u_NABY/status/1033699969289543682

自撮り＋ワールドクリエイションみたいなアプリです。
VRMキャラで街のフィールドを歩き回ったり、オブジェクトを設置したりできます。
光源の設定が細かく、スクリーンショットには独特の味があります。
けもフレRPGの作者。

== ツール

mqdlさんのXISMO
https://twitter.com/mqdl/status/1022747807646539776
https://twitter.com/mqdl/status/1028796028563025921



== 現在開発中のもの

=== VRコラボ
作者：karukaru @_karukaru_
https://com.nicovideo.jp/live_archives/co70543
https://com.nicovideo.jp/community/co70543?com_header=1


VR空間を共有してコミュニケーションをするアプリケーションです。
個室のようにも使えるし、バーチャルキャストのようにコメントを拾って凸あり生放送にも使えます。

=== BabiSenGO
作者：やのせん @yanosen_jp

https://twitter.com/yanosen_jp/status/1041484658905571328

OculusGoで


== Unity以外のプラットフォーム

=== THREE.js
https://threejs.org/examples/?q=VRM#webgl_loader_vrm

WebGLライブラリの中で一番使われているライブラリ。
もともとglTF2.0のロードには対応していたので、その流れでVRMに対応している。
物理演算やMETAプロパティの読み込みには非対応です。
利用条件が読み込めないので、自前サービスで使いたい場合は気を付けましょう。

==== FaceVTuber
URL：https://facevtuber.com/
作者：FaceVTuberOfficial @FaceVTuber
プラットフォーム：web

ブラウザ上で顔認識を行い顔追従を行うFaceRigのようなwebサービス。
PMDやFBXと同様にVRMも読み込むことが可能。
THREE.jsでさくっと読み込めるしせっかくだから付けたというおまけ感ある。

==== VRM Three.js AR Sample

URL：https://twitter.com/t_takasaka/status/1036235629741260800
作者：高坂 @t_takasaka

VRMをWebブラウザでAR表示させるサンプルです。

==== VRM Three.js PoseNet Sample
URL：https://github.com/t-takasaka/vrm-three-posenet
作者：高坂 @t_takasaka

THREE.jsとPoseNetを使って動画からVRMにモーションを転写するサンプルコードです。

=== UnrealEngine4 での VRMランタイム

悩ましい状況が続いています。
UE公式がglTFへの対応予定を謳っています。
https://trello.com/b/omtMIw06/gltf-for-ue4
また、OSSのgiTFローダーのプロジェクトもあります。
https://github.com/code4game/glTFForUE4/
しかしながら、VRMに特化してローディグ環境を完成させたという報告はまだありません。
UETokyoのプロジェクトを推進するか、glTFForUE4をフォークして作る人しかありません。
https://github.com/uetokyo/UnrealVRM
