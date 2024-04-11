
            /// Returns the `rustc` SemVer version and additional metadata
            /// like the git short hash and build date.
            pub fn version_meta() -> VersionMeta {
                VersionMeta {
                    semver: Version {
                        major: 1,
                        minor: 79,
                        patch: 0,
                        pre: vec![semver::Identifier::AlphaNumeric("nightly".to_owned()), ],
                        build: vec![],
                    },
                    host: "aarch64-unknown-linux-gnu".to_owned(),
                    short_version_string: "rustc 1.79.0-nightly (8b2459c1f 2024-04-09)".to_owned(),
                    commit_hash: Some("8b2459c1f21187f9792d99310171a15e64feb9cf".to_owned()),
                    commit_date: Some("2024-04-09".to_owned()),
                    build_date: None,
                    channel: Channel::Nightly,
                }
            }
            