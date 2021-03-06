module Styles = {
  open Css;
  let header = merge([Theme.Type.h1, style([marginBottom(`rem(0.5))])]);

  let sectionSubhead =
    merge([
      Theme.Type.sectionSubhead,
      style([
        fontSize(`px(19)),
        lineHeight(`rem(1.75)),
        letterSpacing(`pxFloat(-0.4)),
        media(Theme.MediaQuery.desktop, [maxWidth(`rem(41.))]),
      ]),
    ]);

  let grid =
    style([
      display(`grid),
      paddingTop(`rem(2.)),
      gridTemplateColumns([`rem(11.5), `rem(11.5)]),
      gridAutoRows(`rem(19.3)),
      gridColumnGap(`rem(1.)),
      gridRowGap(`rem(2.)),
      media(
        Theme.MediaQuery.tablet,
        [
          gridTemplateColumns([
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
          ]),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          gridTemplateColumns([
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
          ]),
        ],
      ),
    ]);
};

[@react.component]
let make = (~profiles, ~switchModalState, ~setCurrentIndexAndMembers) => {
  <>
    <h2 id="team" className=Styles.header> {React.string("Meet the Team")} </h2>
    <p className=Styles.sectionSubhead>
      {React.string(
         "Mina is an inclusive open source protocol uniting teams and technicians from San Francisco and around the world.",
       )}
    </p>
    <Spacer height=2. />
    <Rule color=Theme.Colors.digitalBlack />
    <div className=Styles.grid>
      {React.array(
         profiles
         |> Array.map((member: ContentType.GenericMember.t) => {
              <div
                key={member.name}
                onClick={_ => {
                  switchModalState();
                  setCurrentIndexAndMembers(member, profiles);
                }}>
                <SmallCard member />
              </div>
            }),
       )}
    </div>
  </>;
};
