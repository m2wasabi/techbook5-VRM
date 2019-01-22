= アプリケーションを作る

UnityでVRM対応アプリケーションを作るには、VRMのアクティブロードを抑えていればほぼ満足します。
そして、Unityの場合、ライブラリがよくできているので技術的なハードルが非常に低いです。

=== VRMのアクティブロード

VRMファイルのアクティブロードについて、ベストプラクティスはとりすーぷ氏が開墾済みです。@<fn>{5.qiita.tori}
//footnote[5.qiita.tori][@<href>{https://qiita.com/toRisouP/items/7d2c57d7d160f375e2d8}]

では、最もシンプルなVRMモデルロードを見てみましょう。

//list[load_vrm][UniRxを使ったtoRisouP氏のサンプル]{
async void Start()
{
    // VRMファイルを選択、メモリに読み込む(プラットフォーム依存)
    var path = Application.streamingAssetsPath + "/" + "AliciaSolid.vrm";
    var www = new WWW(path);
    await www;

    // 読み込んだバイトデータをパースしてVRMモデルのGameObjectを受け取る
    var go = await VRMImporter.LoadVrmAsync(www.bytes);
    go.transform.position = new Vector3(1, 1, 1);
}
//}

ファイルの内容をメモリに格納するためのプラットフォームごとの処理は、自作する必要があります。
自作アプリに組み込む場合は、ここの作り込みが味噌になるでしょう。

 * ファイルを選ぶ
 * ファイルを開く
 * Meta情報を読み込み、ユーザーに確認させる

完成品の参考として、手前味噌で恐縮ですが、実際の稼働サンプルは筆者作成のVRMLoaderUIを参照ください。@<fn>{4.github.loaderui}
//footnote[4.github.loaderui][@<href>{https://github.com/m2wasabi/VRMLoaderUI}]

=== VRMのメタ情報の読み込み

VRMモデルをシーンに登場させる前に、読み込むモデルの名前やサムネイルを表示させたい場合、VRMのメタ情報を参照します。
VRMのメタ情報は、バイナリ形式のglTFファイル(*.glb)のパースと同じ方法で読み込み可能です。

//list[load_vrm2][Meta情報を読み込むサンプル]{
async void Start()
{
    var path = Application.streamingAssetsPath + "/" + "AliciaSolid.vrm";
    var www = new WWW(path);
    var context = new VRMImporterContext(UniGLTF.UnityPath.FromFullpath(path));
    await www;
    context.ParseGlb(www.bytes);
    var meta = context.ReadMeta();

    // ToDo: VRM情報表示・利用許可UIの表示
    /*
    meta.Title;
    meta.Version;
    meta.Author;
    meta.ContactInformation;
    meta.Reference;
    meta.AllowedUser.ToString();
    meta.ViolentUssage.ToString();
    meta.SexualUssage.ToString();
    meta.CommercialUssage.ToString();
    meta.OtherPermissionUrl;
    meta.LicenseType.ToString();
    meta.OtherLicenseUrl;
    meta.Thumbnail;
    */

    // OKだった場合にのみVRMロード
    var go = await VRMImporter.LoadVrmAsync(www.bytes);
    go.transform.position = new Vector3(1, 1, 1);
}
//}


=== ロード後の処理

VRMをロードした後、モデルを動かすために、モデルオブジェクトにアニメーションやコントローラーを適用する処理が必要になります。
ここでは、ロードしたVRMに、VRIKとBlendShapeController,HandPoseControllerを紐づけるサンプルを示します。
BlendShapeControllerとHandPoseControllerは独自の実装なので、疑似コードと思ってください。

なお、実際に動くコードは、筆者のLiveAvatarのリポジトリで見ることができます。@<fn>{4.liveavatar}
//footnote[4.liveavatar][@<href>{https://github.com/m2wasabi/LiveAvatar/blob/master/Assets/LiveAvatar/AvatarController/VRM/VRMRuntimeLoaderForLiveAvatar.cs,VRMRuntimeLoaderForLiveAvatar.cs}]

VRIKのセットアップについては、のしぷさんのブログ記事が参考になります。@<fn>{4.noshipu}
//footnote[4.noshipu][@<href>{http://www.noshimemo.com/entry/2018/08/03/181149}]

//list[vrm_add_control][Meta情報を読み込むサンプル]{
void OnLoaded()
{
    var humanPoseTransfer = go.AddComponent<UniHumanoid.HumanPoseTransfer>();
    if (m_target != null)
    {
        GameObject.Destroy(m_target.gameObject);
    }
    m_target = humanPoseTransfer;
    SetupTarget();
}

void SetupTarget()
{
    if (m_target != null)
    {
        m_target.Source = m_source;
        m_target.SourceType = UniHumanoid.HumanPoseTransfer.HumanPoseTransferSourceType.HumanPoseTransfer;

        m_blendShape = m_target.GetComponent<VRMBlendShapeProxy>();

        m_firstPerson = m_target.GetComponent<VRMFirstPerson>();

        var animator = m_target.GetComponent<Animator>();
        if (animator != null)
        {
            animator.runtimeAnimatorController = m_animationController;
            VRIK m_vrik = m_target.gameObject.AddComponent<VRIK>();
            m_vrik.AutoDetectReferences();
            m_vrik.solver.spine.headTarget = m_headTarget;
            m_vrik.solver.leftArm.target = m_leftHandTarget;
            m_vrik.solver.rightArm.target = m_rightHandTarget;
            m_vrik.solver.leftArm.stretchCurve = new AnimationCurve();
            m_vrik.solver.rightArm.stretchCurve = new AnimationCurve();
            IKSolverVR.Locomotion m_vrikLoco = m_vrik.solver.locomotion;
            m_vrikLoco.footDistance = 0.1f;
            m_vrikLoco.stepThreshold = 0.2f;

            m_firstPerson.Setup();

            // 自作コントローラーに animatorと blendshapeを送るなど
            _handPoseController.SetAnimaor(animator);
            _blendShapeController.Setup(m_blendShape);
        }
    }
}
//}

本当に、これだけでVRMを読み込んで任意に動かすことができるようになります。簡単ですね。
